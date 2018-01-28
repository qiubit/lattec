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
#include "../scopes/BlockScope.h"

class ClassScope;
class GlobalScope;
class FunctionScope;
class BlockScope;

class ScopeRegistry {
private:
    std::vector<std::unique_ptr<ClassScope>> classScopes;
    std::vector<std::unique_ptr<FunctionScope>> functionScopes;
    std::vector<std::unique_ptr<BlockScope>> blockScopes;
public:
    ClassScope *getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope, ClassType *t);
    FunctionScope *getNewFunctionScope(Context *ctx,
                                       GlobalScope *globalScope,
                                       FunctionType *functionType,
                                       std::string funName,
                                       std::vector<std::string> argNames);
    BlockScope *getNewBlockScope(Context *ctx, TypeRegistry *reg, Scope *parent);
};


#endif //TESTLLVM_SCOPEREGISTRY_H
