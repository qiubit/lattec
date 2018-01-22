//
// Created by Pawel Golinski on 21.01.2018.
//

#ifndef TESTLLVM_STRINGTYPE_H
#define TESTLLVM_STRINGTYPE_H


#include "Type.h"

class StringType : public Type {
public:
    StringType() : Type(STRING_TYPE_ID) { }
    ~StringType() override = default;

    llvm::PointerType *getLlvmType(Context *ctx) override;
};


#endif //TESTLLVM_STRINGTYPE_H
