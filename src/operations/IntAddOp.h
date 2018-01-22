//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTADDOP_H
#define LATTE_INTADDOP_H


#include "../Context.h"
#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntAddOp : public Op {
private:
    static llvm::Value *addInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntAddOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), addInts(ctx, lInt, rInt)) { }
};


#endif //LATTE_INTADDOP_H
