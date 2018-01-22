//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_INTTYPE_H
#define TESTLLVM_INTTYPE_H

#include "Type.h"

class IntType : public Type {
public:
    IntType();
    ~IntType() override = default;

    llvm::IntegerType *getLlvmType(Context *ctx) override;
    llvm::Value *generateValue(Context *ctx, int val);
};


#endif //TESTLLVM_INTTYPE_H
