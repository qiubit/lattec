//
// Created by Pawel Golinski on 21.01.2018.
//

#include "GlobalScopeVisitor.h"


Type *GlobalScopeVisitor::getTypeFromRegistry(antlr4::ParserRuleContext *parsingCtx, const std::string &typeId, TypeRegistry *reg) {
    Type *type = nullptr;
    if (!reg->typeExits(typeId)) {
        type = globalScope->referenceClass(typeId);
    } else {
        type = reg->getType(typeId);
    }
    if (type == nullptr) {
        reportError(parsingCtx, "Invalid return type \"" + typeId + "\"");
    }
    return type;
}

antlrcpp::Any GlobalScopeVisitor::visitFuncDef(LatteParser::FuncDefContext *ctx) {
    TypeRegistry *reg = globalScope->getTypeRegistry();
    std::string funName = ctx->ID()->getText();

    std::string retTypeStr = ctx->type_()->getText();
    Type *returnType = getTypeFromRegistry(ctx, retTypeStr, reg);

    std::vector<Type *> argsType;
    // If this is a class member function, class instance will be supplied as first argument
    if (classVisited != "") {
        argsType.emplace_back(reg->getType(classVisited));
    }
    if (ctx->arg()) {
        for (auto argTypeCtx : ctx->arg()->type_()) {
            Type *argType = getTypeFromRegistry(ctx, argTypeCtx->getText(), reg);
            if (argType == reg->getVoidType()) {
                reportError(ctx, "Invalid function argument of type \"void\"");
                return nullptr;
            }
            argsType.emplace_back(argType);
        }
    }

    try {
        std::vector<std::string> argNames;
        if (classVisited != "")
            argNames.push_back("this");
        if (ctx->arg() != nullptr) {
            for (auto argIdCtx : ctx->arg()->ID()) {
                argNames.push_back(argIdCtx->getText());
            }
        }
        if (classVisited == "") {
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
    // Fetch parent class type
    ClassType *parentClassType = nullptr;
    if (ctx->ID().size() > 1) {
        std::string parentName = ctx->ID()[1]->getText();
        parentClassType = globalScope->referenceClass(parentName);
        if (parentClassType == nullptr) {
            reportError(ctx, "Referenced symbol " + parentName + " is not a class");
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
    TypeRegistry *reg = globalScope->getTypeRegistry();
    Type *declType = getTypeFromRegistry(ctx, ctx->type_()->getText(), reg);
    if (declType == nullptr)
        return nullptr;
    if (declType == reg->getVoidType()) {
        reportError(ctx, "Invalid variable declaration of type \"void\"");
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
