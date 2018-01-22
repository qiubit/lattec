//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntLtOp.h"


llvm::Value *IntLtOp::compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateICmpSLT(lInt, rInt);
}
