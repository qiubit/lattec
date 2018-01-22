//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_CLASSSCOPE_H
#define TESTLLVM_CLASSSCOPE_H


#include "../Context.h"
#include "../registries/TypeRegistry.h"
#include "../IdEnv.h"
#include "GlobalScope.h"

class GlobalScope;

class ClassScope {
private:
    Context *ctx;
    TypeRegistry *reg;
    IdEnv env;
    GlobalScope *globalScope;
public:
    ClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope) : ctx(ctx), reg(reg), globalScope(globalScope) { }
    void declareMemberVariable(const std::string &symbol, Type *t);
    void declareMemberFunction(const std::string &symbol, Type *returnType,
                               std::vector<Type *> argTypes);
    void declareMemberFunction(const std::string &symbol, Type *returnType);

    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol);
};


#endif //TESTLLVM_CLASSSCOPE_H
