//
// Created by Pawel Golinski on 21.01.2018.
//

#include "StringType.h"


llvm::PointerType *StringType::getLlvmType(Context *ctx) {
    return llvm::PointerType::getInt8PtrTy(*ctx->getContext());
}
