//
// Created by Pawel Golinski on 22.01.2018.
//

#include "ConstStringOp.h"


llvm::Value *ConstStringOp::generateConstString(Context *ctx, const std::string &str) {
    return ctx->getStringGlobal(str);
}
