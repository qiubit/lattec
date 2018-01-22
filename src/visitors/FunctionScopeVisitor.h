//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_FUNCTIONSCOPEVISITOR_H
#define LATTE_FUNCTIONSCOPEVISITOR_H


#include "../parser/LatteBaseVisitor.h"

// Binds BlockScopes to FunctionScopes

// Checks for:
// - Duplicate declarations
// - Missing declarations
// But inside function bodies


class FunctionScopeVisitor : public LatteBaseVisitor {
private:
    std::unordered_set<LatteParser::StmtContext *> invalidStmts;
    std::vector<std::string> errors;
    LatteParser::StmtContext *currentStmt = nullptr;
    LatteParser::ExprContext *currentExpr = nullptr;
public:
    antlrcpp::Any visitProgram(LatteParser::ProgramContext *ctx) override;

    antlrcpp::Any visitFuncDef(LatteParser::FuncDefContext *ctx) override;

    antlrcpp::Any visitFunTopDef(LatteParser::FunTopDefContext *ctx) override;

    antlrcpp::Any visitClassDef(LatteParser::ClassDefContext *ctx) override;

    antlrcpp::Any visitClassFunDef(LatteParser::ClassFunDefContext *ctx) override;

    antlrcpp::Any visitClassVarDef(LatteParser::ClassVarDefContext *ctx) override;

    antlrcpp::Any visitClassBody(LatteParser::ClassBodyContext *ctx) override;

    antlrcpp::Any visitArg(LatteParser::ArgContext *ctx) override;

    antlrcpp::Any visitBlock(LatteParser::BlockContext *ctx) override;

    antlrcpp::Any visitEmpty(LatteParser::EmptyContext *ctx) override;

    antlrcpp::Any visitBlockStmt(LatteParser::BlockStmtContext *ctx) override;

    antlrcpp::Any visitDecl(LatteParser::DeclContext *ctx) override;

    antlrcpp::Any visitAss(LatteParser::AssContext *ctx) override;

    antlrcpp::Any visitIncr(LatteParser::IncrContext *ctx) override;

    antlrcpp::Any visitDecr(LatteParser::DecrContext *ctx) override;

    antlrcpp::Any visitRet(LatteParser::RetContext *ctx) override;

    antlrcpp::Any visitVRet(LatteParser::VRetContext *ctx) override;

    antlrcpp::Any visitCond(LatteParser::CondContext *ctx) override;

    antlrcpp::Any visitCondElse(LatteParser::CondElseContext *ctx) override;

    antlrcpp::Any visitWhile(LatteParser::WhileContext *ctx) override;

    antlrcpp::Any visitSExp(LatteParser::SExpContext *ctx) override;

    antlrcpp::Any visitInt(LatteParser::IntContext *ctx) override;

    antlrcpp::Any visitStr(LatteParser::StrContext *ctx) override;

    antlrcpp::Any visitBool(LatteParser::BoolContext *ctx) override;

    antlrcpp::Any visitVoid(LatteParser::VoidContext *ctx) override;

    antlrcpp::Any visitClass(LatteParser::ClassContext *ctx) override;

    antlrcpp::Any visitItem(LatteParser::ItemContext *ctx) override;

    antlrcpp::Any visitEId(LatteParser::EIdContext *ctx) override;

    antlrcpp::Any visitEFunCall(LatteParser::EFunCallContext *ctx) override;

    antlrcpp::Any visitEClassDef(LatteParser::EClassDefContext *ctx) override;

    antlrcpp::Any visitERelOp(LatteParser::ERelOpContext *ctx) override;

    antlrcpp::Any visitEClassField(LatteParser::EClassFieldContext *ctx) override;

    antlrcpp::Any visitETrue(LatteParser::ETrueContext *ctx) override;

    antlrcpp::Any visitEOr(LatteParser::EOrContext *ctx) override;

    antlrcpp::Any visitEInt(LatteParser::EIntContext *ctx) override;

    antlrcpp::Any visitEUnOp(LatteParser::EUnOpContext *ctx) override;

    antlrcpp::Any visitETypedNull(LatteParser::ETypedNullContext *ctx) override;

    antlrcpp::Any visitEStr(LatteParser::EStrContext *ctx) override;

    antlrcpp::Any visitEMulOp(LatteParser::EMulOpContext *ctx) override;

    antlrcpp::Any visitEAnd(LatteParser::EAndContext *ctx) override;

    antlrcpp::Any visitEParen(LatteParser::EParenContext *ctx) override;

    antlrcpp::Any visitEFalse(LatteParser::EFalseContext *ctx) override;

    antlrcpp::Any visitEAddOp(LatteParser::EAddOpContext *ctx) override;

    antlrcpp::Any visitEClassFun(LatteParser::EClassFunContext *ctx) override;

    antlrcpp::Any visitAddOp(LatteParser::AddOpContext *ctx) override;

    antlrcpp::Any visitMulOp(LatteParser::MulOpContext *ctx) override;

    antlrcpp::Any visitRelOp(LatteParser::RelOpContext *ctx) override;
};


#endif //LATTE_FUNCTIONSCOPEVISITOR_H
