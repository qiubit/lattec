//
// Created by Pawel Golinski on 22.01.2018.
//

#include "FunctionScopeVisitor.h"

antlrcpp::Any FunctionScopeVisitor::visitProgram(LatteParser::ProgramContext *ctx) {
    return LatteBaseVisitor::visitProgram(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitFuncDef(LatteParser::FuncDefContext *ctx) {
    return LatteBaseVisitor::visitFuncDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitFunTopDef(LatteParser::FunTopDefContext *ctx) {
    return LatteBaseVisitor::visitFunTopDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClassDef(LatteParser::ClassDefContext *ctx) {
    return LatteBaseVisitor::visitClassDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClassFunDef(LatteParser::ClassFunDefContext *ctx) {
    return LatteBaseVisitor::visitClassFunDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClassVarDef(LatteParser::ClassVarDefContext *ctx) {
    return LatteBaseVisitor::visitClassVarDef(ctx);
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
    return LatteBaseVisitor::visitEmpty(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitBlockStmt(LatteParser::BlockStmtContext *ctx) {
    return LatteBaseVisitor::visitBlockStmt(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitDecl(LatteParser::DeclContext *ctx) {
    return LatteBaseVisitor::visitDecl(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitAss(LatteParser::AssContext *ctx) {
    return LatteBaseVisitor::visitAss(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitIncr(LatteParser::IncrContext *ctx) {
    return LatteBaseVisitor::visitIncr(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitDecr(LatteParser::DecrContext *ctx) {
    return LatteBaseVisitor::visitDecr(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitRet(LatteParser::RetContext *ctx) {
    return LatteBaseVisitor::visitRet(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitVRet(LatteParser::VRetContext *ctx) {
    return LatteBaseVisitor::visitVRet(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitCond(LatteParser::CondContext *ctx) {
    return LatteBaseVisitor::visitCond(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitCondElse(LatteParser::CondElseContext *ctx) {
    return LatteBaseVisitor::visitCondElse(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitWhile(LatteParser::WhileContext *ctx) {
    return LatteBaseVisitor::visitWhile(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitSExp(LatteParser::SExpContext *ctx) {
    return LatteBaseVisitor::visitSExp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitInt(LatteParser::IntContext *ctx) {
    return LatteBaseVisitor::visitInt(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitStr(LatteParser::StrContext *ctx) {
    return LatteBaseVisitor::visitStr(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitBool(LatteParser::BoolContext *ctx) {
    return LatteBaseVisitor::visitBool(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitVoid(LatteParser::VoidContext *ctx) {
    return LatteBaseVisitor::visitVoid(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitClass(LatteParser::ClassContext *ctx) {
    return LatteBaseVisitor::visitClass(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitItem(LatteParser::ItemContext *ctx) {
    return LatteBaseVisitor::visitItem(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEId(LatteParser::EIdContext *ctx) {
    return LatteBaseVisitor::visitEId(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEFunCall(LatteParser::EFunCallContext *ctx) {
    return LatteBaseVisitor::visitEFunCall(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEClassDef(LatteParser::EClassDefContext *ctx) {
    return LatteBaseVisitor::visitEClassDef(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitERelOp(LatteParser::ERelOpContext *ctx) {
    return LatteBaseVisitor::visitERelOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEClassField(LatteParser::EClassFieldContext *ctx) {
    return LatteBaseVisitor::visitEClassField(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitETrue(LatteParser::ETrueContext *ctx) {
    return LatteBaseVisitor::visitETrue(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEOr(LatteParser::EOrContext *ctx) {
    return LatteBaseVisitor::visitEOr(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEInt(LatteParser::EIntContext *ctx) {
    return LatteBaseVisitor::visitEInt(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEUnOp(LatteParser::EUnOpContext *ctx) {
    return LatteBaseVisitor::visitEUnOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitETypedNull(LatteParser::ETypedNullContext *ctx) {
    return LatteBaseVisitor::visitETypedNull(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEStr(LatteParser::EStrContext *ctx) {
    return LatteBaseVisitor::visitEStr(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEMulOp(LatteParser::EMulOpContext *ctx) {
    return LatteBaseVisitor::visitEMulOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEAnd(LatteParser::EAndContext *ctx) {
    return LatteBaseVisitor::visitEAnd(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEParen(LatteParser::EParenContext *ctx) {
    return LatteBaseVisitor::visitEParen(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEFalse(LatteParser::EFalseContext *ctx) {
    return LatteBaseVisitor::visitEFalse(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEAddOp(LatteParser::EAddOpContext *ctx) {
    return LatteBaseVisitor::visitEAddOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitEClassFun(LatteParser::EClassFunContext *ctx) {
    return LatteBaseVisitor::visitEClassFun(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitAddOp(LatteParser::AddOpContext *ctx) {
    return LatteBaseVisitor::visitAddOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitMulOp(LatteParser::MulOpContext *ctx) {
    return LatteBaseVisitor::visitMulOp(ctx);
}

antlrcpp::Any FunctionScopeVisitor::visitRelOp(LatteParser::RelOpContext *ctx) {
    return LatteBaseVisitor::visitRelOp(ctx);
}
