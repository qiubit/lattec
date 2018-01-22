//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_BLOCKSCOPE_H
#define TESTLLVM_BLOCKSCOPE_H


#include "Scope.h"
#include "../IdEnv.h"
#include "../registries/TypeRegistry.h"

class BlockScope : public Scope {
private:
    TypeRegistry *reg;
    Scope *parent;
    IdEnv env;

public:
    BlockScope(TypeRegistry *reg, Scope *parent) : reg(reg), parent(parent) { }
    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) override;
};


#endif //TESTLLVM_BLOCKSCOPE_H
