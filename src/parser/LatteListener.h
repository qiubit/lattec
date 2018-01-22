
// Generated from Latte.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "LatteParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LatteParser.
 */
class  LatteListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(LatteParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(LatteParser::ProgramContext *ctx) = 0;

  virtual void enterFuncDef(LatteParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(LatteParser::FuncDefContext *ctx) = 0;

  virtual void enterFunTopDef(LatteParser::FunTopDefContext *ctx) = 0;
  virtual void exitFunTopDef(LatteParser::FunTopDefContext *ctx) = 0;

  virtual void enterClassDef(LatteParser::ClassDefContext *ctx) = 0;
  virtual void exitClassDef(LatteParser::ClassDefContext *ctx) = 0;

  virtual void enterClassFunDef(LatteParser::ClassFunDefContext *ctx) = 0;
  virtual void exitClassFunDef(LatteParser::ClassFunDefContext *ctx) = 0;

  virtual void enterClassVarDef(LatteParser::ClassVarDefContext *ctx) = 0;
  virtual void exitClassVarDef(LatteParser::ClassVarDefContext *ctx) = 0;

  virtual void enterClassBody(LatteParser::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(LatteParser::ClassBodyContext *ctx) = 0;

  virtual void enterArg(LatteParser::ArgContext *ctx) = 0;
  virtual void exitArg(LatteParser::ArgContext *ctx) = 0;

  virtual void enterBlock(LatteParser::BlockContext *ctx) = 0;
  virtual void exitBlock(LatteParser::BlockContext *ctx) = 0;

  virtual void enterEmpty(LatteParser::EmptyContext *ctx) = 0;
  virtual void exitEmpty(LatteParser::EmptyContext *ctx) = 0;

  virtual void enterBlockStmt(LatteParser::BlockStmtContext *ctx) = 0;
  virtual void exitBlockStmt(LatteParser::BlockStmtContext *ctx) = 0;

  virtual void enterDecl(LatteParser::DeclContext *ctx) = 0;
  virtual void exitDecl(LatteParser::DeclContext *ctx) = 0;

  virtual void enterAss(LatteParser::AssContext *ctx) = 0;
  virtual void exitAss(LatteParser::AssContext *ctx) = 0;

  virtual void enterIncr(LatteParser::IncrContext *ctx) = 0;
  virtual void exitIncr(LatteParser::IncrContext *ctx) = 0;

  virtual void enterDecr(LatteParser::DecrContext *ctx) = 0;
  virtual void exitDecr(LatteParser::DecrContext *ctx) = 0;

  virtual void enterRet(LatteParser::RetContext *ctx) = 0;
  virtual void exitRet(LatteParser::RetContext *ctx) = 0;

  virtual void enterVRet(LatteParser::VRetContext *ctx) = 0;
  virtual void exitVRet(LatteParser::VRetContext *ctx) = 0;

  virtual void enterCond(LatteParser::CondContext *ctx) = 0;
  virtual void exitCond(LatteParser::CondContext *ctx) = 0;

  virtual void enterCondElse(LatteParser::CondElseContext *ctx) = 0;
  virtual void exitCondElse(LatteParser::CondElseContext *ctx) = 0;

  virtual void enterWhile(LatteParser::WhileContext *ctx) = 0;
  virtual void exitWhile(LatteParser::WhileContext *ctx) = 0;

  virtual void enterSExp(LatteParser::SExpContext *ctx) = 0;
  virtual void exitSExp(LatteParser::SExpContext *ctx) = 0;

  virtual void enterInt(LatteParser::IntContext *ctx) = 0;
  virtual void exitInt(LatteParser::IntContext *ctx) = 0;

  virtual void enterStr(LatteParser::StrContext *ctx) = 0;
  virtual void exitStr(LatteParser::StrContext *ctx) = 0;

  virtual void enterBool(LatteParser::BoolContext *ctx) = 0;
  virtual void exitBool(LatteParser::BoolContext *ctx) = 0;

  virtual void enterVoid(LatteParser::VoidContext *ctx) = 0;
  virtual void exitVoid(LatteParser::VoidContext *ctx) = 0;

  virtual void enterClass(LatteParser::ClassContext *ctx) = 0;
  virtual void exitClass(LatteParser::ClassContext *ctx) = 0;

  virtual void enterItem(LatteParser::ItemContext *ctx) = 0;
  virtual void exitItem(LatteParser::ItemContext *ctx) = 0;

  virtual void enterEId(LatteParser::EIdContext *ctx) = 0;
  virtual void exitEId(LatteParser::EIdContext *ctx) = 0;

  virtual void enterEFunCall(LatteParser::EFunCallContext *ctx) = 0;
  virtual void exitEFunCall(LatteParser::EFunCallContext *ctx) = 0;

  virtual void enterEClassDef(LatteParser::EClassDefContext *ctx) = 0;
  virtual void exitEClassDef(LatteParser::EClassDefContext *ctx) = 0;

  virtual void enterERelOp(LatteParser::ERelOpContext *ctx) = 0;
  virtual void exitERelOp(LatteParser::ERelOpContext *ctx) = 0;

  virtual void enterEClassField(LatteParser::EClassFieldContext *ctx) = 0;
  virtual void exitEClassField(LatteParser::EClassFieldContext *ctx) = 0;

  virtual void enterETrue(LatteParser::ETrueContext *ctx) = 0;
  virtual void exitETrue(LatteParser::ETrueContext *ctx) = 0;

  virtual void enterEOr(LatteParser::EOrContext *ctx) = 0;
  virtual void exitEOr(LatteParser::EOrContext *ctx) = 0;

  virtual void enterEInt(LatteParser::EIntContext *ctx) = 0;
  virtual void exitEInt(LatteParser::EIntContext *ctx) = 0;

  virtual void enterEUnOp(LatteParser::EUnOpContext *ctx) = 0;
  virtual void exitEUnOp(LatteParser::EUnOpContext *ctx) = 0;

  virtual void enterETypedNull(LatteParser::ETypedNullContext *ctx) = 0;
  virtual void exitETypedNull(LatteParser::ETypedNullContext *ctx) = 0;

  virtual void enterEStr(LatteParser::EStrContext *ctx) = 0;
  virtual void exitEStr(LatteParser::EStrContext *ctx) = 0;

  virtual void enterEMulOp(LatteParser::EMulOpContext *ctx) = 0;
  virtual void exitEMulOp(LatteParser::EMulOpContext *ctx) = 0;

  virtual void enterEAnd(LatteParser::EAndContext *ctx) = 0;
  virtual void exitEAnd(LatteParser::EAndContext *ctx) = 0;

  virtual void enterEParen(LatteParser::EParenContext *ctx) = 0;
  virtual void exitEParen(LatteParser::EParenContext *ctx) = 0;

  virtual void enterEFalse(LatteParser::EFalseContext *ctx) = 0;
  virtual void exitEFalse(LatteParser::EFalseContext *ctx) = 0;

  virtual void enterEAddOp(LatteParser::EAddOpContext *ctx) = 0;
  virtual void exitEAddOp(LatteParser::EAddOpContext *ctx) = 0;

  virtual void enterEClassFun(LatteParser::EClassFunContext *ctx) = 0;
  virtual void exitEClassFun(LatteParser::EClassFunContext *ctx) = 0;

  virtual void enterAddOp(LatteParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(LatteParser::AddOpContext *ctx) = 0;

  virtual void enterMulOp(LatteParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(LatteParser::MulOpContext *ctx) = 0;

  virtual void enterRelOp(LatteParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(LatteParser::RelOpContext *ctx) = 0;


};

