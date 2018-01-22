//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTMULOP_H
#define LATTE_INTMULOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntMulOp : public Op {
private:
    static llvm::Value *multiplyInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntMulOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), multiplyInts(ctx, lInt, rInt)) { }
};


#endif //LATTE_INTMULOP_H
