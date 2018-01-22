//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntNeqOp.h"


llvm::Value *IntNeqOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpNE(lInt, rInt);
}
