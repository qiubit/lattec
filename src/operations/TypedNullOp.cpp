//
// Created by Pawel Golinski on 22.01.2018.
//

#include "TypedNullOp.h"


llvm::Value *TypedNullOp::getNullPtr(Context *ctx, TypeRegistry *reg) {
    return llvm::ConstantPointerNull::get(reg->getBytePtrType()->getLlvmType(ctx));
}
