//
// Created by Pawel Golinski on 22.01.2018.
//

#include "VarOp.h"


llvm::Value *VarOp::loadVar(Context *ctx, llvm::Value *varAllocd) {
    return ctx->getBuilder()->CreateLoad(varAllocd);
}
