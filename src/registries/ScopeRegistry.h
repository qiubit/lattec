//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_SCOPEREGISTRY_H
#define TESTLLVM_SCOPEREGISTRY_H

#include <vector>
#include <memory>

#include "../scopes/ClassScope.h"
#include "../scopes/GlobalScope.h"
#include "../scopes/FunctionScope.h"

class ClassScope;
class GlobalScope;
class FunctionScope;

class ScopeRegistry {
private:
    std::vector<std::unique_ptr<ClassScope>> classScopes;
    std::vector<std::unique_ptr<FunctionScope>> functionScopes;
public:
    ClassScope *getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope);
    FunctionScope *getNewFunctionScope(GlobalScope *globalScope, FunctionType *functionType, std::vector<std::string> argNames);
};


#endif //TESTLLVM_SCOPEREGISTRY_H
