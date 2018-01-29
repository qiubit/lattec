
// Generated from Latte.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "LatteListener.h"


/**
 * This class provides an empty implementation of LatteListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LatteBaseListener : public LatteListener {
public:

  virtual void enterProgram(LatteParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(LatteParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFuncDef(LatteParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(LatteParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFunTopDef(LatteParser::FunTopDefContext * /*ctx*/) override { }
  virtual void exitFunTopDef(LatteParser::FunTopDefContext * /*ctx*/) override { }

  virtual void enterClassDef(LatteParser::ClassDefContext * /*ctx*/) override { }
  virtual void exitClassDef(LatteParser::ClassDefContext * /*ctx*/) override { }

  virtual void enterClassFunDef(LatteParser::ClassFunDefContext * /*ctx*/) override { }
  virtual void exitClassFunDef(LatteParser::ClassFunDefContext * /*ctx*/) override { }

  virtual void enterClassVarDef(LatteParser::ClassVarDefContext * /*ctx*/) override { }
  virtual void exitClassVarDef(LatteParser::ClassVarDefContext * /*ctx*/) override { }

  virtual void enterClassBody(LatteParser::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(LatteParser::ClassBodyContext * /*ctx*/) override { }

  virtual void enterArg(LatteParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(LatteParser::ArgContext * /*ctx*/) override { }

  virtual void enterBlock(LatteParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(LatteParser::BlockContext * /*ctx*/) override { }

  virtual void enterEmpty(LatteParser::EmptyContext * /*ctx*/) override { }
  virtual void exitEmpty(LatteParser::EmptyContext * /*ctx*/) override { }

  virtual void enterBlockStmt(LatteParser::BlockStmtContext * /*ctx*/) override { }
  virtual void exitBlockStmt(LatteParser::BlockStmtContext * /*ctx*/) override { }

  virtual void enterDecl(LatteParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(LatteParser::DeclContext * /*ctx*/) override { }

  virtual void enterAss(LatteParser::AssContext * /*ctx*/) override { }
  virtual void exitAss(LatteParser::AssContext * /*ctx*/) override { }

  virtual void enterClassAss(LatteParser::ClassAssContext * /*ctx*/) override { }
  virtual void exitClassAss(LatteParser::ClassAssContext * /*ctx*/) override { }

  virtual void enterArrAss(LatteParser::ArrAssContext * /*ctx*/) override { }
  virtual void exitArrAss(LatteParser::ArrAssContext * /*ctx*/) override { }

  virtual void enterIncr(LatteParser::IncrContext * /*ctx*/) override { }
  virtual void exitIncr(LatteParser::IncrContext * /*ctx*/) override { }

  virtual void enterDecr(LatteParser::DecrContext * /*ctx*/) override { }
  virtual void exitDecr(LatteParser::DecrContext * /*ctx*/) override { }

  virtual void enterRet(LatteParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(LatteParser::RetContext * /*ctx*/) override { }

  virtual void enterVRet(LatteParser::VRetContext * /*ctx*/) override { }
  virtual void exitVRet(LatteParser::VRetContext * /*ctx*/) override { }

  virtual void enterCond(LatteParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(LatteParser::CondContext * /*ctx*/) override { }

  virtual void enterCondElse(LatteParser::CondElseContext * /*ctx*/) override { }
  virtual void exitCondElse(LatteParser::CondElseContext * /*ctx*/) override { }

  virtual void enterWhile(LatteParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(LatteParser::WhileContext * /*ctx*/) override { }

  virtual void enterForArr(LatteParser::ForArrContext * /*ctx*/) override { }
  virtual void exitForArr(LatteParser::ForArrContext * /*ctx*/) override { }

  virtual void enterSExp(LatteParser::SExpContext * /*ctx*/) override { }
  virtual void exitSExp(LatteParser::SExpContext * /*ctx*/) override { }

  virtual void enterStr(LatteParser::StrContext * /*ctx*/) override { }
  virtual void exitStr(LatteParser::StrContext * /*ctx*/) override { }

  virtual void enterArrType(LatteParser::ArrTypeContext * /*ctx*/) override { }
  virtual void exitArrType(LatteParser::ArrTypeContext * /*ctx*/) override { }

  virtual void enterBool(LatteParser::BoolContext * /*ctx*/) override { }
  virtual void exitBool(LatteParser::BoolContext * /*ctx*/) override { }

  virtual void enterClass(LatteParser::ClassContext * /*ctx*/) override { }
  virtual void exitClass(LatteParser::ClassContext * /*ctx*/) override { }

  virtual void enterVoid(LatteParser::VoidContext * /*ctx*/) override { }
  virtual void exitVoid(LatteParser::VoidContext * /*ctx*/) override { }

  virtual void enterInt(LatteParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(LatteParser::IntContext * /*ctx*/) override { }

  virtual void enterItem(LatteParser::ItemContext * /*ctx*/) override { }
  virtual void exitItem(LatteParser::ItemContext * /*ctx*/) override { }

  virtual void enterEId(LatteParser::EIdContext * /*ctx*/) override { }
  virtual void exitEId(LatteParser::EIdContext * /*ctx*/) override { }

  virtual void enterEFunCall(LatteParser::EFunCallContext * /*ctx*/) override { }
  virtual void exitEFunCall(LatteParser::EFunCallContext * /*ctx*/) override { }

  virtual void enterEClassDef(LatteParser::EClassDefContext * /*ctx*/) override { }
  virtual void exitEClassDef(LatteParser::EClassDefContext * /*ctx*/) override { }

  virtual void enterERelOp(LatteParser::ERelOpContext * /*ctx*/) override { }
  virtual void exitERelOp(LatteParser::ERelOpContext * /*ctx*/) override { }

  virtual void enterEClassField(LatteParser::EClassFieldContext * /*ctx*/) override { }
  virtual void exitEClassField(LatteParser::EClassFieldContext * /*ctx*/) override { }

  virtual void enterETrue(LatteParser::ETrueContext * /*ctx*/) override { }
  virtual void exitETrue(LatteParser::ETrueContext * /*ctx*/) override { }

  virtual void enterENewArr(LatteParser::ENewArrContext * /*ctx*/) override { }
  virtual void exitENewArr(LatteParser::ENewArrContext * /*ctx*/) override { }

  virtual void enterEOr(LatteParser::EOrContext * /*ctx*/) override { }
  virtual void exitEOr(LatteParser::EOrContext * /*ctx*/) override { }

  virtual void enterEInt(LatteParser::EIntContext * /*ctx*/) override { }
  virtual void exitEInt(LatteParser::EIntContext * /*ctx*/) override { }

  virtual void enterEUnOp(LatteParser::EUnOpContext * /*ctx*/) override { }
  virtual void exitEUnOp(LatteParser::EUnOpContext * /*ctx*/) override { }

  virtual void enterETypedNull(LatteParser::ETypedNullContext * /*ctx*/) override { }
  virtual void exitETypedNull(LatteParser::ETypedNullContext * /*ctx*/) override { }

  virtual void enterEStr(LatteParser::EStrContext * /*ctx*/) override { }
  virtual void exitEStr(LatteParser::EStrContext * /*ctx*/) override { }

  virtual void enterEMulOp(LatteParser::EMulOpContext * /*ctx*/) override { }
  virtual void exitEMulOp(LatteParser::EMulOpContext * /*ctx*/) override { }

  virtual void enterEAnd(LatteParser::EAndContext * /*ctx*/) override { }
  virtual void exitEAnd(LatteParser::EAndContext * /*ctx*/) override { }

  virtual void enterEArrIdx(LatteParser::EArrIdxContext * /*ctx*/) override { }
  virtual void exitEArrIdx(LatteParser::EArrIdxContext * /*ctx*/) override { }

  virtual void enterEParen(LatteParser::EParenContext * /*ctx*/) override { }
  virtual void exitEParen(LatteParser::EParenContext * /*ctx*/) override { }

  virtual void enterEFalse(LatteParser::EFalseContext * /*ctx*/) override { }
  virtual void exitEFalse(LatteParser::EFalseContext * /*ctx*/) override { }

  virtual void enterEAddOp(LatteParser::EAddOpContext * /*ctx*/) override { }
  virtual void exitEAddOp(LatteParser::EAddOpContext * /*ctx*/) override { }

  virtual void enterEClassFun(LatteParser::EClassFunContext * /*ctx*/) override { }
  virtual void exitEClassFun(LatteParser::EClassFunContext * /*ctx*/) override { }

  virtual void enterAddOp(LatteParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(LatteParser::AddOpContext * /*ctx*/) override { }

  virtual void enterMulOp(LatteParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(LatteParser::MulOpContext * /*ctx*/) override { }

  virtual void enterRelOp(LatteParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(LatteParser::RelOpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

