//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntModOp.h"


llvm::Value *IntModOp::modInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateSRem(lInt, rInt);
}
