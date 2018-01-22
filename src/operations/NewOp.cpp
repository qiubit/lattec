//
// Created by Pawel Golinski on 22.01.2018.
//

#include "NewOp.h"

llvm::Value *NewOp::createNewObject(Context *ctx, ClassType *classType) {
    return classType->allocateClass(ctx);
}
