//
// Created by Pawel Golinski on 22.01.2018.
//

#include "PtrNeqOp.h"


llvm::Value *PtrNeqOp::comparePointers(Context *ctx, llvm::Value *lPtr, llvm::Value *rPtr) {
    auto lPtrInt = ctx->getBuilder()->CreatePtrToInt(lPtr, ctx->getBuilder()->getInt64Ty());
    auto rPtrInt = ctx->getBuilder()->CreatePtrToInt(rPtr, ctx->getBuilder()->getInt64Ty());
    return ctx->getBuilder()->CreateNeg(ctx->getBuilder()->CreateICmpEQ(lPtrInt, rPtrInt));
}
