//
// Created by Pawel Golinski on 22.01.2018.
//

#include "ConstBooleanOp.h"


llvm::Value *ConstBooleanOp::generateConstBoolean(Context *ctx, bool val) {
    return ctx->getBuilder()->getInt1(val);
}
