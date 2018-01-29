//
// Created by Pawel Golinski on 28.01.2018.
//

#ifndef LATTE_CODEGENVISITOR_H
#define LATTE_CODEGENVISITOR_H


#include "../Context.h"
#include "../parser/LatteBaseVisitor.h"
#include "../registries/TypeRegistry.h"
#include "../scopes/Scope.h"
#include "../scopes/GlobalScope.h"

class CodegenVisitor : public LatteBaseVisitor {
private:
    Context *codegenCtx;
    TypeRegistry *reg;
    std::unordered_map<LatteParser::ExprContext *, llvm::Value *> exprValues;
    std::unordered_map<LatteParser::ExprContext *, Type *> exprTypes;
    std::unordered_map<llvm::BasicBlock *, bool> blockTerminated;
    std::unordered_map<LatteParser::StmtContext *, Scope *> stmtScopes;
    Scope *currentScope = nullptr;
    GlobalScope *globalScope;
    std::string visitedClass = "";
    std::vector<std::string> errors;
    ScopeRegistry *scopeReg;
    llvm::Instruction *currentEntryBr = nullptr;
    std::string currentDeclType = "";

    void reportError(antlr4::ParserRuleContext *ctx, std::string msg);

public:
    CodegenVisitor(Context *codegenCtx, TypeRegistry *reg, GlobalScope *globalScope,
                   std::unordered_map<LatteParser::ExprContext *, Type *> exprTypes,
                   std::unordered_map<LatteParser::StmtContext *, Scope *> stmtScopes,
                   ScopeRegistry *scopeReg)
            : codegenCtx(codegenCtx), reg(reg), globalScope(globalScope),
              exprTypes(exprTypes), stmtScopes(stmtScopes), scopeReg(scopeReg) { }

    std::vector<std::string> getErrors() { return errors; }

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
};


#endif //LATTE_CODEGENVISITOR_H
