
// Generated from Latte.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "LatteVisitor.h"


/**
 * This class provides an empty implementation of LatteVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LatteBaseVisitor : public LatteVisitor {
public:

  virtual antlrcpp::Any visitProgram(LatteParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(LatteParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunTopDef(LatteParser::FunTopDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassDef(LatteParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassFunDef(LatteParser::ClassFunDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassVarDef(LatteParser::ClassVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassBody(LatteParser::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg(LatteParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(LatteParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmpty(LatteParser::EmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockStmt(LatteParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(LatteParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAss(LatteParser::AssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassAss(LatteParser::ClassAssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncr(LatteParser::IncrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecr(LatteParser::DecrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(LatteParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVRet(LatteParser::VRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(LatteParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondElse(LatteParser::CondElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile(LatteParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSExp(LatteParser::SExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(LatteParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr(LatteParser::StrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool(LatteParser::BoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoid(LatteParser::VoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass(LatteParser::ClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitItem(LatteParser::ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEId(LatteParser::EIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEFunCall(LatteParser::EFunCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEClassDef(LatteParser::EClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitERelOp(LatteParser::ERelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEClassField(LatteParser::EClassFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitETrue(LatteParser::ETrueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEOr(LatteParser::EOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEInt(LatteParser::EIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEUnOp(LatteParser::EUnOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitETypedNull(LatteParser::ETypedNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEStr(LatteParser::EStrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEMulOp(LatteParser::EMulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEAnd(LatteParser::EAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEParen(LatteParser::EParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEFalse(LatteParser::EFalseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEAddOp(LatteParser::EAddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEClassFun(LatteParser::EClassFunContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddOp(LatteParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulOp(LatteParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(LatteParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

