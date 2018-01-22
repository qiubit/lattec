//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_BOOLEANTYPE_H
#define TESTLLVM_BOOLEANTYPE_H


#include "Type.h"

class BooleanType : public Type {
public:
    BooleanType() : Type(BOOLEAN_TYPE_ID) { };
    ~BooleanType() override = default;
    llvm::IntegerType *getLlvmType(Context *ctx) override;
    llvm::Value *generateValue(Context *ctx, bool val);
};


#endif //TESTLLVM_BOOLEANTYPE_H
