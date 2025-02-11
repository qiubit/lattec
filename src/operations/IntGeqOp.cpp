//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntGeqOp.h"


llvm::Value *IntGeqOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpSGE(lInt, rInt);
}
