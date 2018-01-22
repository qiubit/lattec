//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntDivOp.h"


llvm::Value *IntDivOp::divInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateSDiv(lInt, rInt);
}
