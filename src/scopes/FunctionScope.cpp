//
// Created by Pawel Golinski on 21.01.2018.
//

#include "FunctionScope.h"

FunctionScope::FunctionScope(Context *ctx, GlobalScope *globalScope, FunctionType *functionType, std::string funName,
                             std::vector<std::string> argNames) {
    this->ctx = ctx;
    this->globalScope = globalScope;
    this->functionType = functionType;
    // The name function is present in in globalScope
    this->functionName = funName;

    if (argNames.size() != this->functionType->getArgsType().size()) {
        throw std::invalid_argument("Function argument list not compatible with function type [unequal size]");
    }
    if (parent != nullptr && (argNames.empty() || argNames[0] != "this"))
        throw std::runtime_error("First argument of class function should be \"this\"");
    // Check for duplicate argument symbols
    std::unordered_set<std::string> set;
    for (auto &str : argNames) {
        if (set.find(str) != set.end()) {
            throw std::invalid_argument("Duplicate definition of symbol \"" + str + "\"");
        }
        set.insert(str);
    }

    for (size_t i = 0 ; i < argNames.size(); i++) {
        IdEnvEntry &entry = idEnv.addEnvEntryForId(argNames[i], this->functionType->getArgsType()[i]);
    }

    functionArgNames = argNames;
}

IdEnvEntry *FunctionScope::getSymbolIdEnvEntry(const std::string &symbol) {
    if (idEnv.envEntryExists(symbol))
        return &idEnv.getEnvEntryForId(symbol);
    else if (parent != nullptr)
        return parent->getSymbolIdEnvEntry(symbol);
    else
        return globalScope->getSymbolIdEnvEntry(symbol);
}

void FunctionScope::defineFunctionParameterVars() {
    functionLlvm = ctx->getBuilder()->GetInsertBlock()->getParent();
    auto fnArgsType = functionType->getArgsType();
    std::vector<llvm::Argument *> fnArgs;
    for (auto it = functionLlvm->arg_begin(); it != functionLlvm->arg_end(); it++)
        fnArgs.push_back(&(*it));
    assert(fnArgs.size() == this->functionType->getArgsType().size());
    for (size_t i = 0; i < fnArgs.size(); i++) {
        auto paramName = functionArgNames[i];
        IdEnvEntry &envEntry = idEnv.getEnvEntryForId(paramName);
        envEntry.setEntryAlloca(ctx->getBuilder()->CreateAlloca(fnArgsType[i]->getLlvmType(ctx)));
        ctx->getBuilder()->CreateStore(fnArgs[i], envEntry.getEntryAlloca());
    }
}

void FunctionScope::setParent(ClassScope *classScope) {
    this->parent = classScope;
    classScope->bindClassInstanceBytePtr(
            ctx->getBuilder()->CreateLoad(idEnv.getEnvEntryForId("this").getEntryAlloca())
    );
}

void FunctionScope::declareVariable(const std::string &symbol, Type *t) {
    assert(false && "declareVariable unimplemented");
}
