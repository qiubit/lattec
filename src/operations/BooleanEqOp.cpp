//
// Created by Pawel Golinski on 22.01.2018.
//

#include "BooleanEqOp.h"


llvm::Value *BooleanEqOp::compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool) {
    return ctx->getBuilder()->CreateICmpEQ(lBool, rBool);
}
