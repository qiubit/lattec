//
// Created by Pawel Golinski on 21.01.2018.
//

#include "ClassScope.h"

IdEnvEntry *ClassScope::getSymbolIdEnvEntry(const std::string &symbol) {
    classType->initializeMemberData();

    // Fetch symbol from local IdEnv if already defined
    if (env.envEntryExists(symbol))
        return &env.getEnvEntryForId(symbol);

    Type *classMemberType = classType->getMemberType(symbol);
    // In this case, symbol defines some member of underlying class, so we try to return its IdEnvEntrt
    if (classMemberType != nullptr) {
        // If the symbol is a function, we redirect to globalScope, where it should be defined
        if (classMemberType->isFunctionType())
            return globalScope->getSymbolIdEnvEntry(className + "." + symbol);
        // Else, we redirect to this ClassScope env, where it will be defined
        else {
            IdEnvEntry *envEntry = &env.addEnvEntryForId(symbol, classMemberType);
            defineClassMemberVariable(symbol);
            return envEntry;
        }
    }

    // Fallback if symbol is not a member of class
    return globalScope->getSymbolIdEnvEntry(symbol);
}

void ClassScope::bindClassInstanceBytePtr(llvm::Value *classPtr) {
    this->classPtr = classPtr;
}

void ClassScope::defineClassMemberVariable(const std::string &symbol) {
    if (this->classPtr == nullptr)
        throw std::runtime_error("Class member cannot be defined - instance is not bound");
    if (!env.envEntryExists(symbol))
        throw std::runtime_error("Symbol \"" + symbol + "\" doesn't define class member variable");
    IdEnvEntry &envEntry = env.getEnvEntryForId(symbol);
    envEntry.setEntryValue(classType->getMemberVariablePtr(ctx, symbol, classPtr));
    envEntry.setEntryAlloca(classType->getMemberVariablePtr(ctx, symbol, classPtr));
}

void ClassScope::declareVariable(const std::string &symbol, Type *t) {
    assert(false && "declareVariable unimplemented");
}

void ClassScope::leaveScope() {
    // Class scope doesn't garbage collect anything
    return;
}

void ClassScope::leaveAllScopes() {
    // Class scope doesn't garbage collect anything
    return;
}
