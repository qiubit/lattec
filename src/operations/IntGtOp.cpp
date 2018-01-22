//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntGtOp.h"


llvm::Value *IntGtOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpSGT(lInt, rInt);
}
