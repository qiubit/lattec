//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_GLOBALSCOPEVISITOR_H
#define TESTLLVM_GLOBALSCOPEVISITOR_H

#include <sstream>
#include <vector>
#include <string>

#include "../parser/LatteBaseVisitor.h"
#include "../scopes/GlobalScope.h"

class GlobalScopeVisitor : public LatteBaseVisitor {
private:
    GlobalScope *globalScope;
    std::string classVisited = "";
    std::vector<std::string> errors;

    void reportError(antlr4::ParserRuleContext *ctx, std::string msg);
    Type *getTypeFromRegistry(antlr4::ParserRuleContext *parsingCtx, const std::string &typeId, TypeRegistry *reg);
public:
    GlobalScopeVisitor(GlobalScope *globalScope) : globalScope(globalScope) { }

    antlrcpp::Any visitFuncDef(LatteParser::FuncDefContext *ctx) override;

    antlrcpp::Any visitFunTopDef(LatteParser::FunTopDefContext *ctx) override;

    antlrcpp::Any visitClassDef(LatteParser::ClassDefContext *ctx) override;

    antlrcpp::Any visitClassFunDef(LatteParser::ClassFunDefContext *ctx) override;

    antlrcpp::Any visitClassVarDef(LatteParser::ClassVarDefContext *ctx) override;

    antlrcpp::Any visitClassBody(LatteParser::ClassBodyContext *ctx) override;

    const std::vector<std::string> &getErrors();
};


#endif //TESTLLVM_GLOBALSCOPEVISITOR_H
