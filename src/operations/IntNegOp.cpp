//
// Created by Pawel Golinski on 22.01.2018.
//

#include "IntNegOp.h"


llvm::Value *IntNegOp::negateInt(Context *ctx, llvm::Value *val) {
    return ctx->getBuilder()->CreateNeg(val);
}
