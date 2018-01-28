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
    Context *ctx;
    TypeRegistry *reg;
    Scope *parent;
    IdEnv env;

public:
    BlockScope(Context *ctx, TypeRegistry *reg, Scope *parent) : ctx(ctx), reg(reg), parent(parent) { }
    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) override;
    void declareVariable(const std::string &symbol, Type *t) override;
};


#endif //TESTLLVM_BLOCKSCOPE_H
