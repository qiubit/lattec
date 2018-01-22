//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_FUNCTIONSCOPE_H
#define TESTLLVM_FUNCTIONSCOPE_H

#include <unordered_set>
#include <stdexcept>

#include "GlobalScope.h"
#include "../IdEnv.h"


class GlobalScope;

// TODO: Holds id -> llvm::Value data?
class FunctionScope {
private:
    FunctionType *functionType;
    GlobalScope *globalScope;
    IdEnv idEnv;

public:
    FunctionScope(GlobalScope *globalScope, FunctionType *functionType, std::vector<std::string> argNames);
};


#endif //TESTLLVM_FUNCTIONSCOPE_H
