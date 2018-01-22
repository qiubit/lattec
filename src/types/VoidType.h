//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_VOIDTYPE_H
#define TESTLLVM_VOIDTYPE_H


#include "Type.h"

class VoidType : public Type {
public:
    VoidType() : Type(VOID_TYPE_ID) { }
    ~VoidType() override = default;

    llvm::Type *getLlvmType(Context *ctx) override;
};


#endif //TESTLLVM_VOIDTYPE_H
