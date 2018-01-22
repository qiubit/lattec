//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_SCOPEREGISTRY_H
#define TESTLLVM_SCOPEREGISTRY_H

#include <vector>
#include <memory>

#include "../scopes/ClassScope.h"
#include "../scopes/GlobalScope.h"

class ClassScope;
class GlobalScope;

class ScopeRegistry {
private:
    std::vector<std::unique_ptr<ClassScope>> classScopes;
public:
    ClassScope *getNewClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope);
};


#endif //TESTLLVM_SCOPEREGISTRY_H
