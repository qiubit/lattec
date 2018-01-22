//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntAddOp.h"


llvm::Value *IntAddOp::addInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt) {
    return ctx->getBuilder()->CreateAdd(lInt, rInt);
}
