//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_PTREQOP_H
#define LATTE_PTREQOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class PtrEqOp : public Op {
private:
    static llvm::Value *comparePointers(Context *ctx, llvm::Value *lPtr, llvm::Value *rPtr);

public:
    PtrEqOp(Context *ctx, TypeRegistry *reg, llvm::Value *lPtr, llvm::Value *rPtr)
            : Op(reg->getBooleanType(), comparePointers(ctx, lPtr, rPtr)) { }
};


#endif //LATTE_PTREQOP_H
