//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_FUNCTIONSCOPE_H
#define TESTLLVM_FUNCTIONSCOPE_H

#include <unordered_set>
#include <stdexcept>
#include <string>

#include "Scope.h"
#include "GlobalScope.h"
#include "../IdEnv.h"


class GlobalScope;
class ClassScope;

// TODO: Holds id -> llvm::Value data?
class FunctionScope : public Scope {
private:
    Context *ctx;
    FunctionType *functionType;
    GlobalScope *globalScope;
    ClassScope *parent = nullptr;
    IdEnv idEnv;

    std::string functionName;
    std::vector<std::string> functionArgNames;
    llvm::Function *functionLlvm;

public:
    FunctionScope(Context *ctx,
                  GlobalScope *globalScope,
                  FunctionType *functionType,
                  std::string funName,
                  std::vector<std::string> argNames);
    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) override;
    void defineFunctionParameterVars();
    void setParent(ClassScope *classScope);
    FunctionType *getFunctionType() { return functionType; }
    void declareVariable(const std::string &symbol, Type *t) override;

    void leaveScope() override;

    void leaveAllScopes() override;
};


#endif //TESTLLVM_FUNCTIONSCOPE_H
