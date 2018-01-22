//
// Created by Pawel Golinski on 22.01.2018.
//

#include "BooleanOrOp.h"


llvm::Value *BooleanOrOp::compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool) {
    return ctx->getBuilder()->CreateOr(lBool, rBool);
}
