//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_CLASSSCOPE_H
#define TESTLLVM_CLASSSCOPE_H


#include "../Context.h"
#include "../registries/TypeRegistry.h"
#include "../IdEnv.h"
#include "GlobalScope.h"
#include "Scope.h"

class GlobalScope;

class ClassScope : public Scope {
private:
    Context *ctx;
    TypeRegistry *reg;
    GlobalScope *globalScope;
    ClassType *classType;
    std::string className;
    llvm::Value *classPtr = nullptr;

    IdEnv env;

public:
    ClassScope(Context *ctx, TypeRegistry *reg, GlobalScope *globalScope, ClassType *classType)
            : ctx(ctx), reg(reg), globalScope(globalScope), classType(classType), className(classType->getTypeId()) { }
    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) override;
    // Should be called before defining any class variable
    void bindClassInstanceBytePtr(llvm::Value *classPtr);
    void defineClassMemberVariable(const std::string &symbol);
    void declareVariable(const std::string &symbol, Type *t) override;

    void leaveScope() override;

    void leaveAllScopes() override;
};


#endif //TESTLLVM_CLASSSCOPE_H
