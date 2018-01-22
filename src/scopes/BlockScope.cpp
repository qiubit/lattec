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
