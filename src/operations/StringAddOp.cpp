//
// Created by Pawel Golinski on 22.01.2018.
//

#include "StringAddOp.h"


llvm::Value *StringAddOp::concatStrings(Context *ctx, llvm::Value *lStr, llvm::Value *rStr) {
    return ctx->getBuilder()->CreateCall(
            ctx->getModule()->getFunction("concatStrings"),
            std::vector<llvm::Value *>{lStr, rStr}
    );
}
