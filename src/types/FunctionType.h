//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_FUNCTIONTYPE_H
#define TESTLLVM_FUNCTIONTYPE_H


#include "NamedType.h"
#include "../Context.h"

#include <vector>
#include <map>

class FunctionType : public Type {
private:
    Type *retType;
    std::vector<Type *> argsType;
    std::map<llvm::LLVMContext *, llvm::FunctionType *> inferredLlvmTypes;

    llvm::FunctionType *inferLlvmType(Context *ctx);

    bool thisFlag = false;
public:
    FunctionType(Type *retType, std::vector<Type *> &argsType);
    FunctionType(Type *retType, std::vector<Type *> &&argsType);

    bool operator== (const Type &rhs) const override;
    llvm::Type *getLlvmType(Context *ctx) override;
    llvm::Function *generateFunction(Context *ctx, const std::string &name);
    const Type* getRetType();
    const std::vector<Type *> getArgsType();

    bool isFunctionType() const override;
    void setThisFlag() { thisFlag = true; }
};


#endif //TESTLLVM_FUNCTIONTYPE_H
