//
// Created by Pawel Golinski on 21.01.2018.
//

#include "GlobalScopeVisitor.h"

// Fetch appropriate type from TypeRegistry
Type *GlobalScopeVisitor::getTypeFromRegistry(antlr4::ParserRuleContext *parsingCtx, LatteParser::Type_Context *typeCtx, TypeRegistry *reg) {
    Type *type = nullptr;
    std::string typeId = typeCtx->getText();

    // Check if array, if yes - if one-dimensional
    LatteParser::ArrTypeContext *arrTypeCtx = dynamic_cast<LatteParser::ArrTypeContext *>(typeCtx);
    if (arrTypeCtx != nullptr) {
        LatteParser::ArrTypeContext *sndArrType = dynamic_cast<LatteParser::ArrTypeContext *>(arrTypeCtx->type_());
        if (sndArrType != nullptr) {
            reportError(parsingCtx, "Multidimensional arrays not supported, abandoning compile");
            return reg->getVoidType();
        }
        typeId = arrTypeCtx->type_()->getText();
    }


    // If type is not present, we forward reference it as a class (currently only class is named type)
    if (!reg->typeExits(typeId)) {
        type = globalScope->referenceClass(typeId);
    }
    // Otherwise, we fetch it straight from TypeRegistry
    else {
        type = reg->getType(typeId);
    }

    // Finally, if we were processing "inside-array" type, wrap it into array again
    if (arrTypeCtx != nullptr) {
        type = reg->getArrayType(type);
    }

    // This shouldn't happen - in either branch of if stmt above, type should get fetched
    if (type == nullptr) {
        reportError(parsingCtx, "Invalid return type \"" + typeId + "\"");
    }

    return type;
}

antlrcpp::Any GlobalScopeVisitor::visitFuncDef(LatteParser::FuncDefContext *ctx) {
    // Visits top-def function definition or class function definition
    TypeRegistry *reg = globalScope->getTypeRegistry();
    std::string funName = ctx->ID()->getText();

    // Fetch function return type
    Type *returnType = getTypeFromRegistry(ctx, ctx->type_(), reg);

    // Fetch function arguments type
    std::vector<Type *> argsType;
    // If this is a class member function, class instance will be supplied as first argument
    if (classVisited != "") {
        argsType.emplace_back(reg->getType(classVisited));
    }
    // Fills argsType vector
    if (ctx->arg()) {
        for (auto argTypeCtx : ctx->arg()->type_()) {
            Type *argType = getTypeFromRegistry(ctx, argTypeCtx, reg);
            if (argType == reg->getVoidType()) {
                reportError(ctx, "Invalid function argument of type \"void\"");
                return nullptr;
            }
            argsType.emplace_back(argType);
        }
    }

    try {
        std::vector<std::string> argNames;
        // If function is a class member function, than the first argument will be accessible under name "self"
        if (!classVisited.empty())
            argNames.emplace_back("self");
        if (ctx->arg() != nullptr) {
            for (auto argIdCtx : ctx->arg()->ID()) {
                argNames.push_back(argIdCtx->getText());
            }
        }
        if (classVisited.empty()) {
            globalScope->declareFunction(funName, returnType, argsType);
            globalScope->defineFunction(funName);
            globalScope->createFunctionScope(funName, argNames);
        } else {
            globalScope->declareClassFunction(classVisited, funName, returnType, argsType);
            globalScope->defineClassFunction(classVisited, funName);
            globalScope->createFunctionScope(classVisited + "." + funName, argNames);
        }
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
        return nullptr;
    }

    return LatteBaseVisitor::visitFuncDef(ctx);
}

antlrcpp::Any GlobalScopeVisitor::visitFunTopDef(LatteParser::FunTopDefContext *ctx) {
    return LatteBaseVisitor::visitFunTopDef(ctx);
}

antlrcpp::Any GlobalScopeVisitor::visitClassDef(LatteParser::ClassDefContext *ctx) {
    // Fetch parent class type, if present
    ClassType *parentClassType = nullptr;
    if (ctx->ID().size() > 1) {
        std::string parentName = ctx->ID()[1]->getText();
        parentClassType = globalScope->referenceClass(parentName);
        if (parentClassType == nullptr) {
            reportError(ctx, "Referenced symbol \"" + parentName + "\" is not a class");
            return nullptr;
        }
    }

    // Fetch class type itself and visit its definitions
    std::string className = ctx->ID()[0]->getText();
    ClassType *classType;
    try {
        classType = globalScope->defineClass(className);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
        return nullptr;
    }
    classType->setParentClass(parentClassType);
    classVisited = className;

    visit(ctx->classBody());

    classVisited = "";
    return nullptr;
}

antlrcpp::Any GlobalScopeVisitor::visitClassFunDef(LatteParser::ClassFunDefContext *ctx) {
    return LatteBaseVisitor::visitClassFunDef(ctx);
}

antlrcpp::Any GlobalScopeVisitor::visitClassVarDef(LatteParser::ClassVarDefContext *ctx) {
    // Visits class member variable definition - this adds appropriate member metadata to corresponding ClassType
    TypeRegistry *reg = globalScope->getTypeRegistry();
    Type *declType = getTypeFromRegistry(ctx, ctx->type_(), reg);
    if (declType == nullptr)
        return nullptr;
    if (declType == reg->getVoidType()) {
        reportError(ctx, "Invalid member variable declaration of type \"void\"");
        return nullptr;
    }
    for (auto itemCtx : ctx->item()) {
        if (itemCtx->expr()) {
            reportError(itemCtx, "Assignment disallowed in class definition");
            return nullptr;
        }
        try {
            globalScope->defineClassVariable(classVisited, itemCtx->ID()->getText(), declType);
        } catch (std::invalid_argument &e) {
            reportError(itemCtx, e.what());
            return nullptr;
        }
    }
    return LatteBaseVisitor::visitClassVarDef(ctx);
}

antlrcpp::Any GlobalScopeVisitor::visitClassBody(LatteParser::ClassBodyContext *ctx) {
    return LatteBaseVisitor::visitClassBody(ctx);
}

const std::vector<std::string> &GlobalScopeVisitor::getErrors() {
    return errors;
}

void GlobalScopeVisitor::reportError(antlr4::ParserRuleContext *ctx, std::string msg) {
    std::ostringstream os;
    size_t line = ctx->start->getLine();
    size_t column = ctx->start->getCharPositionInLine();

    os << "line " << line << ":" << column << " " << msg;

    errors.push_back(os.str());
}
