//
// Created by Pawel Golinski on 22.01.2018.
//

#include "BooleanNotOp.h"


llvm::Value *BooleanNotOp::negateBoolean(Context *ctx, llvm::Value *val) {
    return ctx->getBuilder()->CreateNot(val);
}
