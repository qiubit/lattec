//
// Created by Pawel Golinski on 21.01.2018.
//

#include "BlockScope.h"

IdEnvEntry *BlockScope::getSymbolIdEnvEntry(const std::string &symbol) {
    if (env.envEntryExists(symbol)) {
        IdEnvEntry &entry = env.getEnvEntryForId(symbol);
        return &entry;
    } else
        return parent->getSymbolIdEnvEntry(symbol);
}


void BlockScope::declareVariable(const std::string &symbol, Type *t) {
    if (env.envEntryExists(symbol))
        throw std::invalid_argument("Symbol \"" + symbol + "\" already defined in current scope");
    else {
        env.addEnvEntryForId(symbol, t);
    }
}

void BlockScope::leaveScope() {
    auto envEntries = env.getEnvEntries();
    for (auto &it : envEntries) {
        IdEnvEntry *envEntry = it.second;
        assert(envEntry != nullptr);
        if (envEntry->getEntryType() != nullptr && envEntry->getEntryType()->getTypeId() == "string") {
            if (envEntry->getEntryAlloca() != nullptr) {
                llvm::Function *derefString = ctx->getModule()->getFunction("derefString");
                auto strVal = ctx->getBuilder()->CreateLoad(envEntry->getEntryAlloca());
                ctx->getBuilder()->CreateCall(derefString, strVal);
            }
        }
    }
}

void BlockScope::leaveAllScopes() {
    leaveScope();
    if (parent != nullptr)
        parent->leaveAllScopes();
}
