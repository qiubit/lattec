//
// Created by Pawel Golinski on 20.01.2018.
//

#include "BooleanType.h"

llvm::IntegerType *BooleanType::getLlvmType(Context *ctx) {
    return llvm::IntegerType::getInt1Ty(*ctx->getContext());
}

llvm::Value *BooleanType::generateValue(Context *ctx, bool val) {
    return ctx->getBuilder()->getInt1(val);
}
