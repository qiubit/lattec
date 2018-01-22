//
// Created by Pawel Golinski on 22.01.2018.
//

#include "ConstIntOp.h"


llvm::Value *ConstIntOp::generateConstInt(Context *ctx, int val) {
    return ctx->getBuilder()->getInt32(val);
}
