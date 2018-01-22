//
// Created by Pawel Golinski on 21.01.2018.
//

#include "VoidType.h"

llvm::Type *VoidType::getLlvmType(Context *ctx) {
    return llvm::Type::getVoidTy(*ctx->getContext());
}
