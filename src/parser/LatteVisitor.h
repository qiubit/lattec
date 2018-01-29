
// Generated from Latte.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "LatteParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LatteParser.
 */
class  LatteVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LatteParser.
   */
    virtual antlrcpp::Any visitProgram(LatteParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(LatteParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitFunTopDef(LatteParser::FunTopDefContext *context) = 0;

    virtual antlrcpp::Any visitClassDef(LatteParser::ClassDefContext *context) = 0;

    virtual antlrcpp::Any visitClassFunDef(LatteParser::ClassFunDefContext *context) = 0;

    virtual antlrcpp::Any visitClassVarDef(LatteParser::ClassVarDefContext *context) = 0;

    virtual antlrcpp::Any visitClassBody(LatteParser::ClassBodyContext *context) = 0;

    virtual antlrcpp::Any visitArg(LatteParser::ArgContext *context) = 0;

    virtual antlrcpp::Any visitBlock(LatteParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitEmpty(LatteParser::EmptyContext *context) = 0;

    virtual antlrcpp::Any visitBlockStmt(LatteParser::BlockStmtContext *context) = 0;

    virtual antlrcpp::Any visitDecl(LatteParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitAss(LatteParser::AssContext *context) = 0;

    virtual antlrcpp::Any visitClassAss(LatteParser::ClassAssContext *context) = 0;

    virtual antlrcpp::Any visitIncr(LatteParser::IncrContext *context) = 0;

    virtual antlrcpp::Any visitDecr(LatteParser::DecrContext *context) = 0;

    virtual antlrcpp::Any visitRet(LatteParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitVRet(LatteParser::VRetContext *context) = 0;

    virtual antlrcpp::Any visitCond(LatteParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitCondElse(LatteParser::CondElseContext *context) = 0;

    virtual antlrcpp::Any visitWhile(LatteParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitSExp(LatteParser::SExpContext *context) = 0;

    virtual antlrcpp::Any visitInt(LatteParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitStr(LatteParser::StrContext *context) = 0;

    virtual antlrcpp::Any visitBool(LatteParser::BoolContext *context) = 0;

    virtual antlrcpp::Any visitVoid(LatteParser::VoidContext *context) = 0;

    virtual antlrcpp::Any visitClass(LatteParser::ClassContext *context) = 0;

    virtual antlrcpp::Any visitItem(LatteParser::ItemContext *context) = 0;

    virtual antlrcpp::Any visitEId(LatteParser::EIdContext *context) = 0;

    virtual antlrcpp::Any visitEFunCall(LatteParser::EFunCallContext *context) = 0;

    virtual antlrcpp::Any visitEClassDef(LatteParser::EClassDefContext *context) = 0;

    virtual antlrcpp::Any visitERelOp(LatteParser::ERelOpContext *context) = 0;

    virtual antlrcpp::Any visitEClassField(LatteParser::EClassFieldContext *context) = 0;

    virtual antlrcpp::Any visitETrue(LatteParser::ETrueContext *context) = 0;

    virtual antlrcpp::Any visitEOr(LatteParser::EOrContext *context) = 0;

    virtual antlrcpp::Any visitEInt(LatteParser::EIntContext *context) = 0;

    virtual antlrcpp::Any visitEUnOp(LatteParser::EUnOpContext *context) = 0;

    virtual antlrcpp::Any visitETypedNull(LatteParser::ETypedNullContext *context) = 0;

    virtual antlrcpp::Any visitEStr(LatteParser::EStrContext *context) = 0;

    virtual antlrcpp::Any visitEMulOp(LatteParser::EMulOpContext *context) = 0;

    virtual antlrcpp::Any visitEAnd(LatteParser::EAndContext *context) = 0;

    virtual antlrcpp::Any visitEParen(LatteParser::EParenContext *context) = 0;

    virtual antlrcpp::Any visitEFalse(LatteParser::EFalseContext *context) = 0;

    virtual antlrcpp::Any visitEAddOp(LatteParser::EAddOpContext *context) = 0;

    virtual antlrcpp::Any visitEClassFun(LatteParser::EClassFunContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(LatteParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(LatteParser::MulOpContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(LatteParser::RelOpContext *context) = 0;


};

