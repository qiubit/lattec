//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ClassScope.h"

void ClassScope::declareMemberVariable(const std::string &symbol, Type *t) {
    if (env.envEntryExists(symbol))
        throw std::invalid_argument("Symbol \"" + symbol + "\" already defined in current scope");
    env.addEnvEntryForId(symbol, t);
}

void ClassScope::declareMemberFunction(const std::string &symbol, Type *returnType, std::vector<Type *> argTypes) {
    if (env.envEntryExists(symbol))
        throw std::invalid_argument("Symbol \"" + symbol + "\" already defined in current scope");
    FunctionType *fType = reg->getFunctionType(returnType, argTypes);
    env.addEnvEntryForId(symbol, fType);
}

void ClassScope::declareMemberFunction(const std::string &symbol, Type *returnType) {
    if (env.envEntryExists(symbol))
        throw std::invalid_argument("Symbol \"" + symbol + "\" already defined in current scope");
    FunctionType *fType = reg->getFunctionType(returnType);
    env.addEnvEntryForId(symbol, fType);
}

IdEnvEntry *ClassScope::getSymbolIdEnvEntry(const std::string &symbol) {
    if (env.envEntryExists(symbol))
        return &env.getEnvEntryForId(symbol);
    else
        return globalScope->getSymbolIdEnvEntry(symbol);
}

