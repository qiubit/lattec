//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ClassScopeEnv.h"

ClassScope *ClassScopeEnv::getScopeForSymbol(const std::string &symbol) {
    if (symbolToClassScope.find(symbol) != symbolToClassScope.end()) {
        return symbolToClassScope.find(symbol)->second;
    }
    return nullptr;
}

void ClassScopeEnv::defineScopeForSymbol(const std::string &symbol, ClassScope *scope) {
    symbolToClassScope[symbol] = scope;
}
