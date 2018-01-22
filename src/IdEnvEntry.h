//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_ENVENTRY_H
#define TESTLLVM_ENVENTRY_H

#include <string>
#include "types/Type.h"

class IdEnvEntry {
private:
    std::string entryId;
    Type *entryType;

    llvm::AllocaInst *entryAlloca = nullptr;
    llvm::Function *entryFunction = nullptr;
public:
    IdEnvEntry(std::string entryId, Type *entryType) : entryId(std::move(entryId)), entryType(entryType) { }
    const std::string &getEntryId() const { return entryId; }
    Type *getEntryType() const { return entryType; }

    llvm::AllocaInst *getEntryAlloca() const { return entryAlloca; }
    llvm::Function *getEntryFunction() const { return entryFunction; }

    void setEntryAlloca(llvm::AllocaInst *val) { entryAlloca = val; }
    void setEntryFunction(llvm::Function *val) { entryFunction = val; }
};

namespace std {
    template<> struct hash<IdEnvEntry>
    {
        using result_type = std::size_t;
        result_type operator()(const IdEnvEntry &e)
        {
            return std::hash<std::string>{}(e.getEntryId());
        }
    };
}

#endif //TESTLLVM_ENVENTRY_H
