//
// Created by Pawel Golinski on 22.01.2018.
//

#include "BooleanAndOp.h"


llvm::Value *BooleanAndOp::compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool) {
    return ctx->getBuilder()->CreateAnd(lBool, rBool);
}
