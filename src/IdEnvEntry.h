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

    llvm::Value *entryAlloca = nullptr;
    llvm::Function *entryFunction = nullptr;
    llvm::Value *entryValue = nullptr;
public:
    IdEnvEntry(std::string entryId, Type *entryType) : entryId(std::move(entryId)), entryType(entryType) { }
    const std::string &getEntryId() const { return entryId; }
    Type *getEntryType() const { return entryType; }

    llvm::Value *getEntryAlloca() const { return entryAlloca; }
    llvm::Function *getEntryFunction() const { return entryFunction; }
    llvm::Value *getEntryValue() const { return entryValue; }

    void setEntryAlloca(llvm::Value *val) { entryAlloca = val; }
    void setEntryFunction(llvm::Function *val) { entryFunction = val; }
    void setEntryValue(llvm::Value *val) { entryValue = val; }
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
