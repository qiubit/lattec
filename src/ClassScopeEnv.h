//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_CLASSSCOPEENV_H
#define TESTLLVM_CLASSSCOPEENV_H

#include <unordered_map>
#include <string>

#include "scopes/ClassScope.h"

class ClassScopeEnv {
private:
    std::unordered_map<std::string, ClassScope *> symbolToClassScope;
public:
    ClassScope *getScopeForSymbol(const std::string &symbol);
    void defineScopeForSymbol(const std::string &symbol, ClassScope *scope);
};


#endif //TESTLLVM_CLASSSCOPEENV_H
