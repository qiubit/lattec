//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ScopeRegistry.h"


ClassScope *ScopeRegistry::getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope, ClassType *t) {
    classScopes.push_back(std::make_unique<ClassScope>(ctx, reg, globalScope, t));
    return classScopes.back().get();
}

FunctionScope *ScopeRegistry::getNewFunctionScope(Context *ctx,
                                                  GlobalScope *globalScope,
                                                  FunctionType *functionType,
                                                  std::string funName,
                                                  std::vector<std::string> argNames) {
    std::unique_ptr<FunctionScope> fScope =
            std::make_unique<FunctionScope>(ctx, globalScope, functionType, funName, argNames);
    functionScopes.push_back(std::move(fScope));
    return functionScopes.back().get();
}

BlockScope *ScopeRegistry::getNewBlockScope(Context *ctx, TypeRegistry *reg, Scope *parent) {
    blockScopes.push_back(std::make_unique<BlockScope>(ctx, reg, parent));
    return blockScopes.back().get();
}
