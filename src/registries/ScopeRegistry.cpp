//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ScopeRegistry.h"


ClassScope *ScopeRegistry::getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope) {
    classScopes.push_back(std::make_unique<ClassScope>(ctx, reg, globalScope));
    return classScopes.back().get();
}
