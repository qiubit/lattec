//
// Created by Pawel Golinski on 22.01.2018.
//

#include "BooleanNeqOp.h"


llvm::Value *BooleanNeqOp::compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool) {
    return ctx->getBuilder()->CreateICmpNE(lBool, rBool);
}
