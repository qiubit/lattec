//
// Created by Pawel Golinski on 28.01.2018.
//

#include "CodegenVisitor.h"
#include "../operations/ConstBooleanOp.h"
#include "../operations/IntAddOp.h"
#include "../operations/StringAddOp.h"
#include "../operations/ConstStringOp.h"
#include "../operations/TypedNullOp.h"
#include "../operations/IntMulOp.h"
#include "../operations/IntDivOp.h"
#include "../operations/IntModOp.h"
#include "../operations/ClassVarOp.h"
#include "../operations/NewOp.h"
#include "../operations/IntNegOp.h"
#include "../operations/BooleanNotOp.h"
#include "../operations/IntEqOp.h"
#include "../operations/IntNeqOp.h"
#include "../operations/IntLeqOp.h"
#include "../operations/IntLtOp.h"
#include "../operations/IntGeqOp.h"
#include "../operations/IntGtOp.h"
#include "../operations/BooleanEqOp.h"
#include "../operations/BooleanNeqOp.h"
#include "../operations/PtrEqOp.h"
#include "../operations/PtrNeqOp.h"
#include "../operations/ConstIntOp.h"


void CodegenVisitor::reportError(antlr4::ParserRuleContext *ctx, std::string msg) {
    std::ostringstream os;
    size_t line = ctx->start->getLine();
    size_t column = ctx->start->getCharPositionInLine();

    os << "line " << line << ":" << column << " " << msg;

    errors.push_back(os.str());
}

antlrcpp::Any CodegenVisitor::visitProgram(LatteParser::ProgramContext *ctx) {
    return LatteBaseVisitor::visitProgram(ctx);
}

antlrcpp::Any CodegenVisitor::visitFuncDef(LatteParser::FuncDefContext *ctx) {
    IdEnvEntry *envEntry;
    if (visitedClass.empty())
        envEntry = globalScope->getSymbolIdEnvEntry(ctx->ID()->getText());
    else
        envEntry = globalScope->getSymbolIdEnvEntry(visitedClass + "." + ctx->ID()->getText());
    FunctionScope *functionScope;
    if (visitedClass.empty())
        functionScope = globalScope->getFunctionScope(ctx->ID()->getText());
    else
        functionScope = globalScope->getFunctionScope(visitedClass + "." + ctx->ID()->getText());
    llvm::Function *currentFunction = envEntry->getEntryFunction();
    codegenCtx->getBuilder()->SetInsertPoint(&currentFunction->getEntryBlock());

    llvm::BasicBlock *afterEntryBB = llvm::BasicBlock::Create(*codegenCtx->getContext(), "", currentFunction);
    currentEntryBr = codegenCtx->getBuilder()->CreateBr(afterEntryBB);
    blockTerminated[&currentFunction->getEntryBlock()] = true;
    blockTerminated[afterEntryBB] = false;
    codegenCtx->getBuilder()->SetInsertPoint(afterEntryBB);

    Scope *oldScope = currentScope;
    BlockScope *newScope = scopeReg->getNewBlockScope(codegenCtx, reg, functionScope);
    currentScope = newScope;

    visitChildren(ctx);

    for (auto it = this->blockTerminated.begin(); it != this->blockTerminated.end(); it++) {
        if (!(it->second)) {
            // If function is of type void, then we want to exit it on "dead end" block
            if (ctx->type_()->getText() == "void") {
                codegenCtx->getBuilder()->SetInsertPoint(it->first);
                codegenCtx->getBuilder()->CreateRetVoid();
                this->blockTerminated[it->first] = true;
            } else {
                this->reportError(ctx, "Missing return statement");
            }
        }
    }

    currentScope = oldScope;
    currentEntryBr = nullptr;

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitFunTopDef(LatteParser::FunTopDefContext *ctx) {
    return LatteBaseVisitor::visitFunTopDef(ctx);
}

antlrcpp::Any CodegenVisitor::visitClassDef(LatteParser::ClassDefContext *ctx) {
    visitedClass = ctx->ID()[0]->getText();
    visitChildren(ctx);
    visitedClass = "";
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitClassFunDef(LatteParser::ClassFunDefContext *ctx) {
    return LatteBaseVisitor::visitClassFunDef(ctx);
}

antlrcpp::Any CodegenVisitor::visitClassVarDef(LatteParser::ClassVarDefContext *ctx) {
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitClassBody(LatteParser::ClassBodyContext *ctx) {
    return LatteBaseVisitor::visitClassBody(ctx);
}

antlrcpp::Any CodegenVisitor::visitArg(LatteParser::ArgContext *ctx) {
    return LatteBaseVisitor::visitArg(ctx);
}

antlrcpp::Any CodegenVisitor::visitBlock(LatteParser::BlockContext *ctx) {
    return LatteBaseVisitor::visitBlock(ctx);
}

antlrcpp::Any CodegenVisitor::visitEmpty(LatteParser::EmptyContext *ctx) {
    return LatteBaseVisitor::visitEmpty(ctx);
}

antlrcpp::Any CodegenVisitor::visitBlockStmt(LatteParser::BlockStmtContext *ctx) {
    Scope *oldScope = currentScope;
    BlockScope *newScope = scopeReg->getNewBlockScope(codegenCtx, reg, oldScope);
    currentScope = newScope;

    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()])
        visitChildren(ctx);

    currentScope = oldScope;
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitDecl(LatteParser::DeclContext *ctx) {
    currentDeclType = ctx->type_()->getText();
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()])
        visitChildren(ctx);
    currentDeclType = "";
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitAss(LatteParser::AssContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        visit(ctx->expr());
        auto varLoc = currentScope->getSymbolIdEnvEntry(ctx->ID()->getText())->getEntryAlloca();
        codegenCtx->getBuilder()->CreateStore(exprValues[ctx->expr()], varLoc);
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitClassAss(LatteParser::ClassAssContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        visit(ctx->expr()[0]);
        visit(ctx->expr()[1]);
        ClassType *classType = dynamic_cast<ClassType *>(exprTypes[ctx->expr()[0]]);
        llvm::Value *classBytePtr = exprValues[ctx->expr()[0]];
        llvm::Value *classMemberPtr = classType->getMemberVariablePtr(codegenCtx, ctx->ID()->getText(), classBytePtr);
        codegenCtx->getBuilder()->CreateStore(exprValues[ctx->expr()[1]], classMemberPtr);
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitIncr(LatteParser::IncrContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        auto varLoc = currentScope->getSymbolIdEnvEntry(ctx->ID()->getText())->getEntryAlloca();
        auto preIncr = codegenCtx->getBuilder()->CreateLoad(varLoc);
        auto postIncr = codegenCtx->getBuilder()->CreateAdd(preIncr, codegenCtx->getBuilder()->getInt32(1));
        codegenCtx->getBuilder()->CreateStore(postIncr, varLoc);
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitDecr(LatteParser::DecrContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        auto varLoc = currentScope->getSymbolIdEnvEntry(ctx->ID()->getText())->getEntryAlloca();
        auto preDecr = codegenCtx->getBuilder()->CreateLoad(varLoc);
        auto postDecr = codegenCtx->getBuilder()->CreateSub(preDecr, codegenCtx->getBuilder()->getInt32(1));
        codegenCtx->getBuilder()->CreateStore(postDecr, varLoc);
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitRet(LatteParser::RetContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        visit(ctx->expr());
        codegenCtx->getBuilder()->CreateRet(exprValues[ctx->expr()]);
        blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitVRet(LatteParser::VRetContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        codegenCtx->getBuilder()->CreateRetVoid();
        blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitCond(LatteParser::CondContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        if (ctx->expr()->getText() == "true") {
            visit(ctx->stmt());
        } else if (ctx->expr()->getText() == "false") {
            // Do nothing
        } else {
            llvm::BasicBlock *ifBeginBB =
                    llvm::BasicBlock::Create(*codegenCtx->getContext(), "if",
                                             codegenCtx->getBuilder()->GetInsertBlock()->getParent());
            blockTerminated[ifBeginBB] = false;

            llvm::BasicBlock *ifContBB =
                    llvm::BasicBlock::Create(*codegenCtx->getContext(), "ifcont");
            blockTerminated[ifContBB] = false;

            visit(ctx->expr());
            codegenCtx->getBuilder()->CreateCondBr(exprValues[ctx->expr()], ifBeginBB, ifContBB);
            blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;

            codegenCtx->getBuilder()->SetInsertPoint(ifBeginBB);
            visit(ctx->stmt());
            if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
                codegenCtx->getBuilder()->CreateBr(ifContBB);
                blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;
            }

            codegenCtx->getBuilder()->GetInsertBlock()->getParent()->getBasicBlockList().push_back(ifContBB);
            codegenCtx->getBuilder()->SetInsertPoint(ifContBB);
        }
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitCondElse(LatteParser::CondElseContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        if (ctx->expr()->getText() == "true") {
            visit(ctx->stmt()[0]);
        } else if (ctx->expr()->getText() == "false") {
            visit(ctx->stmt()[1]);
        } else {
            bool createIfCont = false;

            llvm::BasicBlock *ifBeginBB =
                    llvm::BasicBlock::Create(*codegenCtx->getContext(), "if",
                                             codegenCtx->getBuilder()->GetInsertBlock()->getParent());
            blockTerminated[ifBeginBB] = false;

            llvm::BasicBlock *elseBeginBB =
                    llvm::BasicBlock::Create(*codegenCtx->getContext(), "else");
            blockTerminated[elseBeginBB] = false;

            llvm::BasicBlock *ifContBB =
                    llvm::BasicBlock::Create(*codegenCtx->getContext(), "ifcont");

            visit(ctx->expr());
            codegenCtx->getBuilder()->CreateCondBr(exprValues[ctx->expr()], ifBeginBB, elseBeginBB);
            blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;

            codegenCtx->getBuilder()->SetInsertPoint(ifBeginBB);
            visit(ctx->stmt()[0]);
            auto ifEndBB = codegenCtx->getBuilder()->GetInsertBlock();
            if (!blockTerminated[ifEndBB]) {
                codegenCtx->getBuilder()->CreateBr(ifContBB);
                blockTerminated[ifEndBB] = true;
                createIfCont = true;
            }

            codegenCtx->getBuilder()->GetInsertBlock()->getParent()->getBasicBlockList().push_back(elseBeginBB);
            codegenCtx->getBuilder()->SetInsertPoint(elseBeginBB);
            visit(ctx->stmt()[1]);
            auto elseEndBB = codegenCtx->getBuilder()->GetInsertBlock();
            if (!blockTerminated[elseEndBB]) {
                codegenCtx->getBuilder()->CreateBr(ifContBB);
                blockTerminated[elseEndBB] = true;
                createIfCont = true;
            }

            if (createIfCont) {
                codegenCtx->getBuilder()->GetInsertBlock()->getParent()->getBasicBlockList().push_back(ifContBB);
                codegenCtx->getBuilder()->SetInsertPoint(ifContBB);
                blockTerminated[ifContBB] = false;
            }
        }
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitWhile(LatteParser::WhileContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
        llvm::BasicBlock *condBB =
                llvm::BasicBlock::Create(*codegenCtx->getContext(), "whileCond",
                                         codegenCtx->getBuilder()->GetInsertBlock()->getParent());
        this->blockTerminated[condBB] = false;

        codegenCtx->getBuilder()->CreateBr(condBB);
        this->blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;

        codegenCtx->getBuilder()->SetInsertPoint(condBB);
        visit(ctx->expr());

        llvm::BasicBlock *whileBB =
                llvm::BasicBlock::Create(*codegenCtx->getContext(), "whileLoop",
                                         codegenCtx->getBuilder()->GetInsertBlock()->getParent());
        this->blockTerminated[whileBB] = false;

        llvm::BasicBlock *whileContBB =
                llvm::BasicBlock::Create(*codegenCtx->getContext(), "whileCont");
        this->blockTerminated[whileContBB] = false;

        codegenCtx->getBuilder()->CreateCondBr(exprValues[ctx->expr()], whileBB, whileContBB);
        this->blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;

        codegenCtx->getBuilder()->SetInsertPoint(whileBB);
        visit(ctx->stmt());
        if (!this->blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()]) {
            codegenCtx->getBuilder()->CreateBr(condBB);
            this->blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()] = true;
        }

        codegenCtx->getBuilder()->GetInsertBlock()->getParent()->getBasicBlockList().push_back(whileContBB);
        codegenCtx->getBuilder()->SetInsertPoint(whileContBB);
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitSExp(LatteParser::SExpContext *ctx) {
    if (!blockTerminated[codegenCtx->getBuilder()->GetInsertBlock()])
        visit(ctx->expr());
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitItem(LatteParser::ItemContext *ctx) {
    if (ctx->expr() != nullptr)
        visit(ctx->expr());

    Type *itemType = reg->getType(currentDeclType);
    currentScope->declareVariable(ctx->ID()->getText(), itemType);
    IdEnvEntry *entry = currentScope->getSymbolIdEnvEntry(ctx->ID()->getText());
    auto varAlloca = codegenCtx->getBuilder()->CreateAlloca(itemType->getLlvmType(codegenCtx));
    if (ctx->expr() != nullptr)
        codegenCtx->getBuilder()->CreateStore(exprValues[ctx->expr()], varAlloca);
    entry->setEntryAlloca(varAlloca);

    if (ctx->expr() == nullptr) {
        if (currentDeclType == "string") {
            codegenCtx->getBuilder()->CreateStore(ConstStringOp(codegenCtx, reg, "").getOpVal(), varAlloca);
        } else if (currentDeclType == "boolean") {
            codegenCtx->getBuilder()->CreateStore(ConstBooleanOp(codegenCtx, reg, false).getOpVal(), varAlloca);
        } else if (currentDeclType == "int") {
            codegenCtx->getBuilder()->CreateStore(ConstIntOp(codegenCtx, reg, 0).getOpVal(), varAlloca);
        } else {
            codegenCtx->getBuilder()->CreateStore(llvm::ConstantPointerNull::get(reg->getBytePtrType()->getLlvmType(codegenCtx)), varAlloca);
        }
    }

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEId(LatteParser::EIdContext *ctx) {
    exprValues[ctx] = codegenCtx->getBuilder()->CreateLoad(
            currentScope->getSymbolIdEnvEntry(ctx->ID()->getText())->getEntryAlloca()
    );
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEFunCall(LatteParser::EFunCallContext *ctx) {
    std::vector<llvm::Value *> fnArgs;
    for (size_t i = 0; i < ctx->expr().size(); i++) {
        visit(ctx->expr()[i]);
        fnArgs.push_back(exprValues[ctx->expr()[i]]);
    }
    auto fn = currentScope->getSymbolIdEnvEntry(ctx->ID()->getText())->getEntryFunction();
    exprValues[ctx] = codegenCtx->getBuilder()->CreateCall(fn, fnArgs);
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEClassDef(LatteParser::EClassDefContext *ctx) {
    ClassType *exprType = dynamic_cast<ClassType *>(exprTypes[ctx]);
    exprValues[ctx] = NewOp(codegenCtx, globalScope->getIdEnv(), exprType).getOpVal();
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitERelOp(LatteParser::ERelOpContext *ctx) {
    auto relOpStr = ctx->relOp()->getText();
    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    auto lVal = exprValues[ctx->expr()[0]];
    auto rVal = exprValues[ctx->expr()[1]];
    if (exprTypes[ctx->expr()[0]] == reg->getIntType()) {
        if (relOpStr == "==") {
            exprValues[ctx] = IntEqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == "!=") {
            exprValues[ctx] = IntNeqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == "<=") {
            exprValues[ctx] = IntLeqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == "<") {
            exprValues[ctx] = IntLtOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == ">=") {
            exprValues[ctx] = IntGeqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == ">") {
            exprValues[ctx] = IntGtOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else {
            throw std::runtime_error("Unsupported ERelOp");
        }
    } else if (exprTypes[ctx->expr()[0]] == reg->getBooleanType()) {
        if (relOpStr == "==") {
            exprValues[ctx] = BooleanEqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == "!=") {
            exprValues[ctx] = BooleanNeqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else {
            throw std::runtime_error("Unsupported ERelOp");
        }
    } else {
        if (relOpStr == "==") {
            exprValues[ctx] = PtrEqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else if (relOpStr == "!=") {
            exprValues[ctx] = PtrNeqOp(codegenCtx, reg, lVal, rVal).getOpVal();
        } else {
            throw std::runtime_error("Unsupported ERelOp");
        }
    }

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEClassField(LatteParser::EClassFieldContext *ctx) {
    visit(ctx->expr());
    ClassType *exprType = dynamic_cast<ClassType *>(exprTypes[ctx->expr()]);
    exprValues[ctx] = ClassVarOp(codegenCtx, exprType, exprValues[ctx->expr()], ctx->ID()->getText()).getOpVal();
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitETrue(LatteParser::ETrueContext *ctx) {
    exprValues[ctx] = ConstBooleanOp(codegenCtx, reg, true).getOpVal();
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEOr(LatteParser::EOrContext *ctx) {
    auto currentFun = codegenCtx->getBuilder()->GetInsertBlock()->getParent();

    visit(ctx->expr()[0]);
    llvm::BasicBlock *firstOrBB = codegenCtx->getBuilder()->GetInsertBlock();
    llvm::Value *lVal = exprValues[ctx->expr()[0]];

    llvm::BasicBlock *restOrBB = llvm::BasicBlock::Create(*codegenCtx->getContext(), "restOr", currentFun);
    blockTerminated[restOrBB] = false;

    llvm::BasicBlock *afterOrBB = llvm::BasicBlock::Create(*codegenCtx->getContext(), "afterOr");
    blockTerminated[afterOrBB] = false;

    codegenCtx->getBuilder()->CreateCondBr(lVal, afterOrBB, restOrBB);
    blockTerminated[firstOrBB] = true;

    codegenCtx->getBuilder()->SetInsertPoint(restOrBB);
    visit(ctx->expr()[1]);
    llvm::Value *rVal = exprValues[ctx->expr()[1]];

    llvm::BasicBlock *lastOrBB = codegenCtx->getBuilder()->GetInsertBlock();
    codegenCtx->getBuilder()->CreateBr(afterOrBB);
    blockTerminated[lastOrBB] = true;

    currentFun->getBasicBlockList().push_back(afterOrBB);
    codegenCtx->getBuilder()->SetInsertPoint(afterOrBB);

    llvm::PHINode *finalVal = codegenCtx->getBuilder()->CreatePHI(llvm::Type::getInt1Ty(*codegenCtx->getContext()), 2, "orVal");
    finalVal->addIncoming(lVal, firstOrBB);
    finalVal->addIncoming(rVal, lastOrBB);
    exprValues[ctx] = finalVal;

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEInt(LatteParser::EIntContext *ctx) {
    exprValues[ctx] = codegenCtx->getBuilder()->getInt(llvm::APInt(32, ctx->getText(), 10));
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEUnOp(LatteParser::EUnOpContext *ctx) {
    char opChar = ctx->getText()[0];

    visit(ctx->expr());
    if (opChar == '-') {
        exprValues[ctx] = IntNegOp(codegenCtx, reg, exprValues[ctx->expr()]).getOpVal();
    } else if (opChar == '!') {
        exprValues[ctx] = BooleanNotOp(codegenCtx, reg, exprValues[ctx->expr()]).getOpVal();
    } else {
        throw std::runtime_error("Unknown EUnOp");
    }
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitETypedNull(LatteParser::ETypedNullContext *ctx) {
    exprValues[ctx] = TypedNullOp(codegenCtx, reg, dynamic_cast<ClassType *>(exprTypes[ctx])).getOpVal();
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEStr(LatteParser::EStrContext *ctx) {
    exprValues[ctx] = ConstStringOp(codegenCtx, reg, ctx->getText().substr(1, ctx->getText().size()-2)).getOpVal();
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEMulOp(LatteParser::EMulOpContext *ctx) {
    auto opStr = ctx->mulOp()->getText();

    llvm::Value *val;

    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    llvm::Value *lVal = exprValues[ctx->expr()[0]];
    llvm::Value *rVal = exprValues[ctx->expr()[1]];

    if (opStr == "*") {
        val = IntMulOp(codegenCtx, reg, lVal, rVal).getOpVal();
    } else if (opStr == "/") {
        val = IntDivOp(codegenCtx, reg, lVal, rVal).getOpVal();
    } else if (opStr == "%") {
        val = IntModOp(codegenCtx, reg, lVal, rVal).getOpVal();
    } else {
        throw std::runtime_error("Unknown mulOp");
    }
    exprValues[ctx] = val;

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEAnd(LatteParser::EAndContext *ctx) {
    auto currentFun = codegenCtx->getBuilder()->GetInsertBlock()->getParent();

    visit(ctx->expr()[0]);
    llvm::BasicBlock *firstAndBB = codegenCtx->getBuilder()->GetInsertBlock();
    llvm::Value *lVal = exprValues[ctx->expr()[0]];

    llvm::BasicBlock *restAndBB = llvm::BasicBlock::Create(*codegenCtx->getContext(), "restAnd", currentFun);
    blockTerminated[restAndBB] = false;

    llvm::BasicBlock *afterAndBB = llvm::BasicBlock::Create(*codegenCtx->getContext(), "afterAnd");
    blockTerminated[afterAndBB] = false;

    codegenCtx->getBuilder()->CreateCondBr(lVal, restAndBB, afterAndBB);
    blockTerminated[firstAndBB] = true;

    codegenCtx->getBuilder()->SetInsertPoint(restAndBB);
    visit(ctx->expr()[1]);
    llvm::Value *rVal = exprValues[ctx->expr()[1]];

    llvm::BasicBlock *lastAndBB = codegenCtx->getBuilder()->GetInsertBlock();
    codegenCtx->getBuilder()->CreateBr(afterAndBB);
    blockTerminated[lastAndBB] = true;

    currentFun->getBasicBlockList().push_back(afterAndBB);
    codegenCtx->getBuilder()->SetInsertPoint(afterAndBB);

    llvm::PHINode *finalVal = codegenCtx->getBuilder()->CreatePHI(codegenCtx->getBuilder()->getInt1Ty(), 2, "andVal");
    finalVal->addIncoming(lVal, firstAndBB);
    finalVal->addIncoming(rVal, lastAndBB);

    exprValues[ctx] = finalVal;

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEParen(LatteParser::EParenContext *ctx) {
    visitChildren(ctx);
    exprValues[ctx] = exprValues[ctx->expr()];
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEFalse(LatteParser::EFalseContext *ctx) {
    llvm::Value *val = ConstBooleanOp(codegenCtx, reg, false).getOpVal();
    exprValues[ctx] = val;
    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEAddOp(LatteParser::EAddOpContext *ctx) {
    llvm::Value *val;

    visit(ctx->expr()[0]);
    visit(ctx->expr()[1]);
    llvm::Value *lVal = exprValues[ctx->expr()[0]];
    llvm::Value *rVal = exprValues[ctx->expr()[1]];

    if (exprTypes[ctx] == reg->getIntType()) {
        if (ctx->addOp()->getText() == "+")
            val = IntAddOp(codegenCtx, reg, lVal, rVal).getOpVal();
        else if (ctx->addOp()->getText() == "-")
            val = codegenCtx->getBuilder()->CreateSub(lVal, rVal);
    } else if (exprTypes[ctx] == reg->getStringType() && ctx->addOp()->getText() == "+") {
        val = StringAddOp(codegenCtx, reg, lVal, rVal).getOpVal();
    } else {
        throw std::runtime_error("EAddOp unknown type");
    }
    exprValues[ctx]=  val;

    return nullptr;
}

antlrcpp::Any CodegenVisitor::visitEClassFun(LatteParser::EClassFunContext *ctx) {
    // Fetch type
    ClassType *classType = dynamic_cast<ClassType *>(exprTypes[ctx->expr()[0]]);
    assert(classType != nullptr);
    visit(ctx->expr()[0]);
    auto classPtr = exprValues[ctx->expr()[0]];

    std::vector<llvm::Value *> fnArgs;
    fnArgs.push_back(classPtr);
    // Fetch function args
    for (size_t i = 1; i < ctx->expr().size(); i++) {
        visit(ctx->expr()[i]);
        fnArgs.push_back(exprValues[ctx->expr()[i]]);
    }

    auto fnPtr = classType->getMemberVariablePtr(codegenCtx, ctx->ID()->getText(), classPtr);
    auto fn = codegenCtx->getBuilder()->CreateLoad(fnPtr);
    exprValues[ctx] = codegenCtx->getBuilder()->CreateCall(fn, fnArgs);

    return LatteBaseVisitor::visitEClassFun(ctx);
}
