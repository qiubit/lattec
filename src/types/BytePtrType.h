//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_BYTEPTRTYPE_H
#define TESTLLVM_BYTEPTRTYPE_H


#include "Type.h"

class BytePtrType : public Type {
public:
    BytePtrType();
    ~BytePtrType() override = default;
    bool operator== (const Type &rhs) const override;
    llvm::PointerType *getLlvmType(Context *ctx) override;
};


#endif //TESTLLVM_BYTEPTRTYPE_H
