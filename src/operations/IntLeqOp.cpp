//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntLeqOp.h"


llvm::Value *IntLeqOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpSLE(lInt, rInt);
}
