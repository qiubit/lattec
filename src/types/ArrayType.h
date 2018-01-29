//
// Created by Pawel Golinski on 29.01.2018.
//

#ifndef LATTE_ARRAYTYPE_H
#define LATTE_ARRAYTYPE_H


#include "Type.h"

class ArrayType : public Type {
private:
    Type *elemType;

public:
    ArrayType(Type *elemType);

    bool isArray() const override { return true; }
    llvm::Type* getLlvmType(Context *ctx) override;

    llvm::Value *getElem(Context *ctx, llvm::Value *arrayPtr, llvm::Value *idx);
    llvm::Value *getElemPtr(Context *ctx, llvm::Value *arrayPtr, llvm::Value *idx);
    llvm::Value *getLength(Context *ctx, llvm::Value *arrayPtr);
    llvm::Value *allocateArray(Context *ctx, llvm::Value *size);
};


#endif //LATTE_ARRAYTYPE_H
