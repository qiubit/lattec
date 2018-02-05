//
// Created by Pawel Golinski on 22.01.2018.
//

#include "FunctionScopeVisitor.h"


bool FunctionScopeVisitor::isRightCompatibleWithLeft(Type *lhs, Type *rhs) {
    if (lhs == rhs)
        return true;
    ClassType *lhsCasted = dynamic_cast<ClassType *>(lhs);
    ClassType *rhsCasted = dynamic_cast<ClassType *>(rhs);
    if (lhsCasted == nullptr || rhsCasted == nullptr)
        return false;
    while (rhsCasted != lhsCasted && rhsCasted != nullptr) {
        rhsCasted = rhsCasted->getParentClass();
    }
    if (rhsCasted == nullptr)
        return false;
    else
        return true;
}

antlrcpp::Any FunctionScopeVisitor::visitArrType(LatteParser::ArrTypeContext *ctx) {
    return LatteBaseVisitor::visitArrType(ctx);
}

// Fetch appropriate type from TypeRegistry
Type *FunctionScopeVisitor::getTypeFromRegistry(LatteParser::Type_Context *typeCtx, TypeRegistry *reg, bool wrapInArr) {
    Type *type = nullptr;
    std::string typeId = typeCtx->getText();

    // Check if array, if yes - if one-dimensional
    LatteParser::ArrTypeContext *arrTypeCtx = nullptr;
    if (!wrapInArr) {
        arrTypeCtx = dynamic_cast<LatteParser::ArrTypeContext *>(typeCtx);
        if (arrTypeCtx != nullptr) {
            LatteParser::ArrTypeContext *sndArrType = dynamic_cast<LatteParser::ArrTypeContext *>(arrTypeCtx->type_());
            if (sndArrType != nullptr)
                throw std::invalid_argument("Multidimensional arrays not supported, abandoning compile");
            typeId = arrTypeCtx->type_()->getText();
        }
    }


    // If type is not present, we forward reference it as a class (currently only class is named type)
    if (!reg->typeExits(typeId)) {
        type = globalScope->referenceClass(typeId);
    }
        // Otherwise, we fetch it straight from TypeRegistry
    else {
        type = reg->getType(typeId);
    }

    if (type == nullptr)
        throw std::invalid_argument("Unknown type \"" + typeCtx->getText() + "\"");

    // Finally, if we were processing "inside-array" type, wrap it into array again
    if (!wrapInArr) {
        if (arrTypeCtx != nullptr) {
            type = reg->getArrayType(type);
        }
    } else {
        if (dynamic_cast<ArrayType *>(type) != nullptr)
            throw std::invalid_argument("Can't wrap type \"" + typeCtx->getText() + "\" into array");
        type = reg->getArrayType(type);
    }

    // This shouldn't happen - in either branch of if stmt above, type should get fetched
    if (type == nullptr)
        throw std::runtime_error("Something went wrong with type \"" + typeCtx->getText() + "\"");

    return type;
}

antlrcpp::Any FunctionScopeVisitor::visitProgram(LatteParser::ProgramContext *ctx) {
    return LatteBaseVisitor::visitProgram(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitFuncDef(LatteParser::FuncDefContext *ctx) {
    auto functionName = ctx->ID()->getText();
    IdEnvEntry *entry;
    if (visitedClass.empty())
        entry = globalScope->getSymbolIdEnvEntry(functionName);
    else
        entry = globalScope->getSymbolIdEnvEntry(visitedClass + "." + functionName);

    llvm::Function *f = entry->getEntryFunction();
    assert(f != nullptr);
    llvm::BasicBlock *BB =
            llvm::BasicBlock::Create(*globalScope->getContext()->getContext(), "entry", f);
    globalScope->getContext()->getBuilder()->SetInsertPoint(BB);

    FunctionScope *fs;
    if (visitedClass.empty())
        fs = globalScope->getFunctionScope(functionName);
    else
        fs = globalScope->getFunctionScope(visitedClass + "." + functionName);
    assert(fs != nullptr);
    fs->defineFunctionParameterVars();
    if (!visitedClass.empty()) {
        ClassType *ct =
                dynamic_cast<ClassType *>(globalScope->getTypeRegistry()->getType(visitedClass));
        assert(ct != nullptr);
        ClassScope *cs =
                scopeReg->getNewClassScope(globalScope->getContext(), globalScope->getTypeRegistry(), globalScope, ct);
        assert(cs != nullptr);
        fs->setParent(cs);
    }

    currentFunctionScope = fs;
    currentScope = scopeReg->getNewBlockScope(globalScope->getContext(), globalScope->getTypeRegistry(), fs);
    visitChildren(ctx);

    currentScope = nullptr;
    currentFunctionScope = nullptr;

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitFunTopDef(LatteParser::FunTopDefContext *ctx) {
    return LatteBaseVisitor::visitFunTopDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClassDef(LatteParser::ClassDefContext *ctx) {
    visitedClass = ctx->ID()[0]->getText();
    visit(ctx->classBody());
    visitedClass = "";
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitClassFunDef(LatteParser::ClassFunDefContext *ctx) {
    return LatteBaseVisitor::visitClassFunDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClassVarDef(LatteParser::ClassVarDefContext *ctx) {
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitClassBody(LatteParser::ClassBodyContext *ctx) {
    return LatteBaseVisitor::visitClassBody(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitArg(LatteParser::ArgContext *ctx) {
    return LatteBaseVisitor::visitArg(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitBlock(LatteParser::BlockContext *ctx) {
    return LatteBaseVisitor::visitBlock(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEmpty(LatteParser::EmptyContext *ctx) {
    stmtScopes[ctx] = currentScope;
    return LatteBaseVisitor::visitEmpty(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitBlockStmt(LatteParser::BlockStmtContext *ctx) {
    Scope *oldScope = currentScope;
    currentScope = scopeReg->getNewBlockScope(globalScope->getContext(), globalScope->getTypeRegistry(), oldScope);
    stmtScopes[ctx] = currentScope;
    visitChildren(ctx);
    currentScope = oldScope;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitDecl(LatteParser::DeclContext *ctx) {
    stmtScopes[ctx] = currentScope;

    Type *declType = getTypeFromRegistry(ctx->type_(), globalScope->getTypeRegistry());
    if (declType == globalScope->getTypeRegistry()->getVoidType() || declType == nullptr) {
        reportError(ctx, "Undefined type \"" + ctx->type_()->getText() + "\"");
        return nullptr;
    }
    currentDeclType = declType;
    try {
        visitChildren(ctx);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }
    currentDeclType = nullptr;

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitAss(LatteParser::AssContext *ctx) {
    stmtScopes[ctx] = currentScope;

    auto lhsName = ctx->ID()->getText();
    IdEnvEntry *lhsIdEnvEntry = currentScope->getSymbolIdEnvEntry(lhsName);
    if (lhsIdEnvEntry == nullptr) {
        reportError(ctx, "Symbol \"" + lhsName + "\" is undefined");
        return nullptr;
    }

    Type *lhsType = lhsIdEnvEntry->getEntryType();
    Type *rhsType;
    try {
        visit(ctx->expr());
        rhsType = exprTypes[ctx->expr()];
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
        return nullptr;
    }
    if (!isRightCompatibleWithLeft(lhsType, rhsType)) {
        reportError(ctx, "Assignment of incompatible types - \"" + lhsType->getTypeId() + "\" and \"" + rhsType->getTypeId() + "\"");
    }
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitClassAss(LatteParser::ClassAssContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visit(ctx->expr()[0]);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
        return nullptr;
    }

    ClassType *classType = dynamic_cast<ClassType *>(exprTypes[ctx->expr()[0]]);
    if (classType == nullptr) {
        reportError(ctx, "Expected class type for \".\" expression");
        return nullptr;
    }
    Type *memberType = classType->getMemberType(ctx->ID()->getText());
    if (memberType == nullptr) {
        reportError(ctx, "Unknown class member \"" + ctx->ID()->getText() + "\"");
        return nullptr;
    }

    try {
        visit(ctx->expr()[1]);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
        return nullptr;
    }
    if (!isRightCompatibleWithLeft(memberType, exprTypes[ctx->expr()[1]])) {
        reportError(ctx, "Assignment of incompatible types - \"" + memberType->getTypeId() + "\" and \"" + exprTypes[ctx->expr()[1]]->getTypeId() + "\"");
        return nullptr;
    }
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitIncr(LatteParser::IncrContext *ctx) {
    stmtScopes[ctx] = currentScope;

    auto lhsName = ctx->ID()->getText();
    IdEnvEntry *lhsIdEnvEntry = currentScope->getSymbolIdEnvEntry(lhsName);
    if (lhsIdEnvEntry == nullptr) {
        reportError(ctx, "Symbol \"" + lhsName + "\" is undefined");
        return nullptr;
    }

    Type *lhsType = lhsIdEnvEntry->getEntryType();
    if (!(*lhsType == *globalScope->getTypeRegistry()->getIntType())) {
        reportError(ctx, "Expected type \"int\" in \"++\" statement");
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitDecr(LatteParser::DecrContext *ctx) {
    stmtScopes[ctx] = currentScope;

    auto lhsName = ctx->ID()->getText();
    IdEnvEntry *lhsIdEnvEntry = currentScope->getSymbolIdEnvEntry(lhsName);
    if (lhsIdEnvEntry == nullptr) {
        reportError(ctx, "Symbol \"" + lhsName + "\" is undefined");
        return nullptr;
    }

    Type *lhsType = lhsIdEnvEntry->getEntryType();
    if (!(*lhsType == *globalScope->getTypeRegistry()->getIntType())) {
        reportError(ctx, "Expected type \"int\" in \"--\" statement");
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitRet(LatteParser::RetContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visit(ctx->expr());
        Type *exprType = exprTypes[ctx->expr()];
        if (!isRightCompatibleWithLeft(currentFunctionScope->getFunctionType()->getRetType(), exprType)) {
            reportError(ctx, "Invalid return expression of type \"" + exprType->getTypeId() + "\"");
        }
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitVRet(LatteParser::VRetContext *ctx) {
    stmtScopes[ctx] = currentScope;

    if (!(*globalScope->getTypeRegistry()->getVoidType() == *currentFunctionScope->getFunctionType()->getRetType())) {
        reportError(ctx, "Invalid return expression of type \"void\"");
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitCond(LatteParser::CondContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visit(ctx->expr());
        Type *exprType = exprTypes[ctx->expr()];
        if (!(*exprType == *globalScope->getTypeRegistry()->getBooleanType())) {
            reportError(ctx, "if condition should have type \"bool\"");
            return nullptr;
        }
        visit(ctx->stmt());
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitCondElse(LatteParser::CondElseContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visit(ctx->expr());
        Type *exprType = exprTypes[ctx->expr()];
        if (!(*exprType == *globalScope->getTypeRegistry()->getBooleanType())) {
            reportError(ctx, "if condition should have type \"bool\"");
            return nullptr;
        }
        visit(ctx->stmt()[0]);
        visit(ctx->stmt()[1]);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitWhile(LatteParser::WhileContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visit(ctx->expr());
        Type *exprType = exprTypes[ctx->expr()];
        if (!(*exprType == *globalScope->getTypeRegistry()->getBooleanType())) {
            reportError(ctx, "if condition should have type \"bool\"");
            return nullptr;
        }
        visit(ctx->stmt());
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitSExp(LatteParser::SExpContext *ctx) {
    stmtScopes[ctx] = currentScope;

    try {
        visitChildren(ctx);
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }

    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitItem(LatteParser::ItemContext *ctx) {
    Type *t = currentDeclType;
    auto varIdStr = ctx->ID()->getText();
    if (ctx->expr() != nullptr) {
        visit(ctx->expr());
        t = exprTypes[ctx->expr()];
    }
    if (!isRightCompatibleWithLeft(currentDeclType, t)) {
        reportError(ctx, "Assignment of incompatible types - \"" + currentDeclType->getTypeId() + "\" and \"" + t->getTypeId() + "\"");
    }
    currentScope->declareVariable(varIdStr, currentDeclType);
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEId(LatteParser::EIdContext *ctx) {
    auto idStr = ctx->ID()->getText();
    IdEnvEntry *envEntry = currentScope->getSymbolIdEnvEntry(idStr);
    if (envEntry == nullptr)
        throw std::invalid_argument("Symbol \"" + ctx->ID()->getText() + "\" is undefined");
    Type *idType = envEntry->getEntryType();
    exprTypes[ctx] = idType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEFunCall(LatteParser::EFunCallContext *ctx) {
    auto funName = ctx->ID()->getText();
    IdEnvEntry *envEntry = currentScope->getSymbolIdEnvEntry(funName);
    if (envEntry == nullptr) {
        reportError(ctx, "Symbol \"" + funName + "\" is not defined");
        return nullptr;
    }
    FunctionType *funType = dynamic_cast<FunctionType *>(envEntry->getEntryType());
    if (funType == nullptr) {
        reportError(ctx, "Symbol \"" + funName + "\" doesn't define a function");
        return nullptr;
    }
    std::vector<Type *> args;
    for (auto exprCtx : ctx->expr()) {
        visit(exprCtx);
        Type *exprType = exprTypes[exprCtx];
        args.emplace_back(exprType);
    }

    if (args.size() != funType->getArgsType().size())
        throw std::invalid_argument("Invalid number of arguments supplied to function \"" + ctx->ID()->getText() + "\"");
    for (size_t i = 0; i < args.size(); i++) {
        Type *funArgT = funType->getArgsType()[i];
        Type *argT = args[i];
        if (!isRightCompatibleWithLeft(funArgT, argT))
            throw std::invalid_argument("Incompatible arguments supplied to function \"" + ctx->ID()->getText() + "\" expected \"" + funArgT->getTypeId() + "\", got \"" + argT->getTypeId() + "\"");
    }
    exprTypes[ctx] = funType->getRetType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEClassDef(LatteParser::EClassDefContext *ctx) {
    ClassType *t = dynamic_cast<ClassType *>(globalScope->getTypeRegistry()->getType(ctx->ID()->getText()));
    if (t == nullptr)
        throw std::invalid_argument("Type \"" + ctx->ID()->getText() + "\" unknown or unsupported in \"new\" operation");
    exprTypes[ctx] = t;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitERelOp(LatteParser::ERelOpContext *ctx) {
    Type *t = nullptr;

    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    Type *lhsType = exprTypes[ctx->expr()[0]];
    Type *rhsType = exprTypes[ctx->expr()[1]];
    if (!(*lhsType == *rhsType)) {
        throw std::invalid_argument("Incompatible types supplied to boolean op \"" + ctx->relOp()->getText() + "\": \"" + lhsType->getTypeId() + "\" and \"" + rhsType->getTypeId() + "\"");
    }
    if (ctx->relOp()->getText() == "==" || ctx->relOp()->getText() == "!=") {
        t = globalScope->getTypeRegistry()->getBooleanType();
    }
    // Except from comparison, relOps supported only for ints
    else if (lhsType != globalScope->getTypeRegistry()->getIntType()) {
        throw std::invalid_argument("Incompatible types supplied to boolean op \"" + ctx->relOp()->getText() + "\": \"" + lhsType->getTypeId() + "\" and \"" + rhsType->getTypeId() + "\"");
    } else {
        t = globalScope->getTypeRegistry()->getBooleanType();
    }

    exprTypes[ctx] = t;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEClassField(LatteParser::EClassFieldContext *ctx) {
    Type *t = nullptr;
    visit(ctx->expr());
    ArrayType *arrExprType = dynamic_cast<ArrayType *>(exprTypes[ctx->expr()]);
    if (arrExprType != nullptr) {
        if (ctx->ID()->getText() != "length")
            throw std::invalid_argument("Attribute \"" + ctx->ID()->getText() + "\" is undefined for arrays");
        exprTypes[ctx] = globalScope->getTypeRegistry()->getIntType();
        return nullptr;
    }
    ClassType *exprType = dynamic_cast<ClassType *>(exprTypes[ctx->expr()]);
    if (exprType == nullptr)
        throw std::invalid_argument("Expected class type for \".\" expression");
    Type *memberType = exprType->getMemberType(ctx->ID()->getText());
    if (memberType == nullptr)
        throw std::invalid_argument("Symbol \"" + ctx->ID()->getText() + "\" is undefined for class \"" + exprType->getTypeId() + "\"");
    exprTypes[ctx] = memberType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitETrue(LatteParser::ETrueContext *ctx) {
    exprTypes[ctx] = globalScope->getTypeRegistry()->getBooleanType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEOr(LatteParser::EOrContext *ctx) {
    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    Type *lhsType = exprTypes[ctx->expr()[0]];
    Type *rhsType = exprTypes[ctx->expr()[1]];
    Type *booleanType = globalScope->getTypeRegistry()->getBooleanType();
    if (lhsType != booleanType || rhsType != booleanType)
        throw std::invalid_argument("Expected two \"boolean\" expressions for \"||\" operation");
    exprTypes[ctx] = booleanType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEInt(LatteParser::EIntContext *ctx) {
    exprTypes[ctx] = globalScope->getTypeRegistry()->getIntType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEUnOp(LatteParser::EUnOpContext *ctx) {
    char opSign = ctx->getText()[0];
    visit(ctx->expr());
    Type *exprType = exprTypes[ctx->expr()];
    if (opSign == '!' && exprType == globalScope->getTypeRegistry()->getBooleanType())
        exprTypes[ctx] = globalScope->getTypeRegistry()->getBooleanType();
    else if (opSign == '-' && exprType == globalScope->getTypeRegistry()->getIntType())
        exprTypes[ctx] =  globalScope->getTypeRegistry()->getIntType();
    else
        throw std::invalid_argument("Invalid type \"" + exprType->getTypeId() + "\" expression for \"" + opSign + "\" operation");
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitETypedNull(LatteParser::ETypedNullContext *ctx) {
    Type *t = globalScope->getTypeRegistry()->getType(ctx->ID()->getText());
    if (t == nullptr)
        throw std::invalid_argument("Unknown type cast \"" + ctx->ID()->getText() + "\"");
    exprTypes[ctx] = t;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEStr(LatteParser::EStrContext *ctx) {
    exprTypes[ctx] = globalScope->getTypeRegistry()->getStringType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEMulOp(LatteParser::EMulOpContext *ctx) {
    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    Type *lhsType = exprTypes[ctx->expr()[0]];
    Type *rhsType = exprTypes[ctx->expr()[1]];
    Type *intType = globalScope->getTypeRegistry()->getIntType();

    if (lhsType != intType || rhsType != intType)
        throw std::invalid_argument("Expected two \"int\" expressions for \"" + ctx->mulOp()->getText() + "\" operation");

    exprTypes[ctx] = intType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEAnd(LatteParser::EAndContext *ctx) {
    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    Type *lhsType = exprTypes[ctx->expr()[0]];
    Type *rhsType = exprTypes[ctx->expr()[1]];
    Type *booleanType = globalScope->getTypeRegistry()->getBooleanType();
    if (lhsType != booleanType || rhsType != booleanType)
        throw std::invalid_argument("Expected two \"boolean\" expressions for \"&&\" operation");
    exprTypes[ctx] = booleanType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEParen(LatteParser::EParenContext *ctx) {
    visit(ctx->expr());
    exprTypes[ctx] = exprTypes[ctx->expr()];
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEFalse(LatteParser::EFalseContext *ctx) {
    exprTypes[ctx] = globalScope->getTypeRegistry()->getBooleanType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEAddOp(LatteParser::EAddOpContext *ctx) {
    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    Type *lhsType = exprTypes[ctx->expr()[0]];
    Type *rhsType = exprTypes[ctx->expr()[1]];
    Type *intType = globalScope->getTypeRegistry()->getIntType();
    Type *stringType = globalScope->getTypeRegistry()->getStringType();

    if (ctx->addOp()->getText() == "+") {
        if (lhsType != rhsType || (lhsType != intType && lhsType != stringType)) {
            throw std::invalid_argument("Incompatible types supplied to boolean op \"+\": \"" + lhsType->getTypeId() + "\" and \"" + rhsType->getTypeId() + "\"");
        }
    } else if (ctx->addOp()->getText() == "-") {
        if (lhsType != rhsType || lhsType != intType) {
            throw std::invalid_argument("Incompatible types supplied to boolean op \"-\": \"" + lhsType->getTypeId() + "\" and \"" + rhsType->getTypeId() + "\"");
        }
    }

    // Since lhsType == rhsType == resultType for AddOp, we can just do this
    exprTypes[ctx] = lhsType;
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEClassFun(LatteParser::EClassFunContext *ctx) {
    visit(ctx->expr()[0]);
    Type *t = exprTypes[ctx->expr()[0]];
    ClassType *ct = dynamic_cast<ClassType *>(t);
    if (ct == nullptr)
        throw std::invalid_argument("Expected class type for \".\" expression");
    std::vector<Type *> argTypes;
    // Note that class will be put into first
    for (auto exprCtx : ctx->expr()) {
        if (exprTypes.find(exprCtx) == exprTypes.end())
            visit(exprCtx);
        argTypes.push_back(exprTypes[exprCtx]);
    }
    FunctionType *ft = dynamic_cast<FunctionType *>(ct->getMemberType(ctx->ID()->getText()));
    if (ft == nullptr)
        throw std::invalid_argument("\"" + ctx->ID()->getText() + "\" is not a class member function");

    if (argTypes.size() != ft->getArgsType().size())
        throw std::invalid_argument("Invalid number of arguments supplied to function \"" + ctx->ID()->getText() + "\"");
    for (size_t i = 0; i < argTypes.size(); i++) {
        Type *funArgT = ft->getArgsType()[i];
        Type *argT = argTypes[i];
        if (!isRightCompatibleWithLeft(funArgT, argT))
            throw std::invalid_argument("Incompatible arguments supplied to function \"" + ctx->ID()->getText() + "\" expected \"" + funArgT->getTypeId() + "\", got \"" + argT->getTypeId() + "\"");
    }

    exprTypes[ctx] = ft->getRetType();
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitArrAss(LatteParser::ArrAssContext *ctx) {
    try {
        visit(ctx->expr()[0]);
        visit(ctx->expr()[1]);
        visit(ctx->expr()[2]);
        ArrayType *arrayType = dynamic_cast<ArrayType *>(exprTypes[ctx->expr()[0]]);
        IntType *idxType = dynamic_cast<IntType *>(exprTypes[ctx->expr()[1]]);
        Type *elemType = exprTypes[ctx->expr()[2]];

        if (arrayType == nullptr)
            throw std::invalid_argument("Expected array type in array assignment");
        if (idxType == nullptr)
            throw std::invalid_argument("Expected \"int\" type as array index");
        if (!isRightCompatibleWithLeft(arrayType->getElemType(), elemType))
            throw std::invalid_argument("Assignment of incompatible types - \"" + arrayType->getElemType()->getTypeId() + "\" and \"" + elemType->getTypeId() + "\"");
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitForArr(LatteParser::ForArrContext *ctx) {
    try {
        visit(ctx->expr());
        ArrayType *arrayType = dynamic_cast<ArrayType *>(exprTypes[ctx->expr()]);
        if (arrayType == nullptr)
            throw std::invalid_argument("Expected array expression in for loop");
        Type *elemDeclared = getTypeFromRegistry(ctx->type_(), globalScope->getTypeRegistry());
        if (!isRightCompatibleWithLeft(arrayType->getElemType(), elemDeclared))
            throw std::invalid_argument("Declared type incompatible with array element type");
        Scope *oldScope = currentScope;
        currentScope = scopeReg->getNewBlockScope(globalScope->getContext(), globalScope->getTypeRegistry(), oldScope);
        currentScope->declareVariable(ctx->ID()->getText(), elemDeclared);
        visit(ctx->stmt());
        currentScope = oldScope;
    } catch (std::invalid_argument &e) {
        reportError(ctx, e.what());
    }
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitENewArr(LatteParser::ENewArrContext *ctx) {
    visit(ctx->expr());
    if (exprTypes[ctx->expr()] != globalScope->getTypeRegistry()->getIntType())
        throw std::invalid_argument("Expected \"int\" type expression in new[] expression");
    exprTypes[ctx] = getTypeFromRegistry(ctx->type_(), globalScope->getTypeRegistry(), true);
    return nullptr;
}

antlrcpp::Any FunctionScopeVisitor::visitEArrIdx(LatteParser::EArrIdxContext *ctx) {
    visit(ctx->expr()[1]);
    if (exprTypes[ctx->expr()[1]] != globalScope->getTypeRegistry()->getIntType())
        throw std::invalid_argument("Expected \"int\" type expression in array indexing expression");
    visit(ctx->expr()[0]);
    ArrayType *arrayType = dynamic_cast<ArrayType *>(exprTypes[ctx->expr()[0]]);
    if (arrayType == nullptr)
        throw std::invalid_argument("Expected array type expression in array indexing expression");
    exprTypes[ctx] = arrayType->getElemType();
    return nullptr;
}

void FunctionScopeVisitor::reportError(antlr4::ParserRuleContext *ctx, std::string msg) {
    std::ostringstream os;
    size_t line = ctx->start->getLine();
    size_t column = ctx->start->getCharPositionInLine();

    os << "line " << line << ":" << column << " " << msg;

    errors.push_back(os.str());
}
