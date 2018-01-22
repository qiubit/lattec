//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_EXPRENV_H
#define LATTE_EXPRENV_H


#include <unordered_map>

#include "parser/LatteParser.h"
#include "types/Type.h"

class ExprEnv {
private:
    std::unordered_map<LatteParser::ExprContext *, Type *> exprTypes;
    std::unordered_map<LatteParser::ExprContext *, llvm::Value *> exprValues;
public:
    Type *markExprType(LatteParser::ExprContext *expr, Type *type);
    llvm::Value *assignExprValue(LatteParser::ExprContext *expr, llvm::Value *value);
    void typeCheckBoolOperation(LatteParser::ExprContext *lExr, LatteParser *rExpr);
};


#endif //LATTE_EXPRENV_H
