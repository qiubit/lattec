//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ScopeRegistry.h"


ClassScope *ScopeRegistry::getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope) {
    classScopes.push_back(std::make_unique<ClassScope>(ctx, reg, globalScope));
    return classScopes.back().get();
}

FunctionScope *ScopeRegistry::getNewFunctionScope(GlobalScope *globalScope, FunctionType *functionType,
                                                  std::vector<std::string> argNames) {
    functionScopes.push_back(std::make_unique<FunctionScope>(globalScope, functionType, argNames));
    return functionScopes.back().get();
}
