//
// Created by Pawel Golinski on 20.01.2018.
//

#include "IntType.h"

IntType::IntType() : Type(INT_TYPE_ID) { }

llvm::IntegerType *IntType::getLlvmType(Context *ctx) {
    return llvm::Type::getInt32Ty(*ctx->getContext());
}

llvm::Value *IntType::generateValue(Context *ctx, int val) {
    return ctx->getBuilder()->getInt32(val);
}
