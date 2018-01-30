//
// Created by Pawel Golinski on 22.01.2018.
//

#include "StringAddOp.h"


llvm::Value *StringAddOp::concatStrings(Context *ctx, llvm::Value *lStr, llvm::Value *rStr) {
    auto toRet = ctx->getBuilder()->CreateCall(
            ctx->getModule()->getFunction("concatStrings"),
            std::vector<llvm::Value *>{lStr, rStr}
    );
    llvm::Function *derefString = ctx->getModule()->getFunction("derefString");
    ctx->getBuilder()->CreateCall(derefString, lStr);
    ctx->getBuilder()->CreateCall(derefString, rStr);
    return toRet;
}
