//
// Created by Pawel Golinski on 22.01.2018.
//

#include "NewOp.h"

llvm::Value *NewOp::createNewObject(Context *ctx, IdEnv *functionEnv, ClassType *classType) {
    auto classPtr = classType->allocateClass(ctx);
    classType->overwriteVirtualFunctionsAndMembers(ctx, functionEnv, classPtr);
    return classPtr;
}
