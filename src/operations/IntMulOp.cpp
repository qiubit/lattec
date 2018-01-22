//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntMulOp.h"


llvm::Value *IntMulOp::multiplyInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateMul(lInt, rInt);
}
