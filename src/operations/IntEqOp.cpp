//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntEqOp.h"


llvm::Value *IntEqOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpEQ(lInt, rInt);
}
