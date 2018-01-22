//
// Created by Pawel Golinski on 21.01.2018.
//

#include "FunctionScope.h"

FunctionScope::FunctionScope(GlobalScope *globalScope, FunctionType *functionType,
                             std::vector<std::string> argNames) {
    this->globalScope = globalScope;
    this->functionType = functionType;

    if (argNames.size() != this->functionType->getArgsType().size()) {
        throw std::invalid_argument("Function argument list not compatible with function type [unequal size]");
    }
    // Check for duplicate argument symbols
    std::unordered_set<std::string> set;
    for (auto &str : argNames) {
        if (set.find(str) != set.end()) {
            throw std::invalid_argument("Duplicate definition of symbol \"" + str + "\"");
        }
        set.insert(str);
    }

    for (size_t i = 0 ; i < argNames.size(); i++) {
        idEnv.addEnvEntryForId(argNames[i], this->functionType->getArgsType()[i]);
    }
}
