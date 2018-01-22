//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTMODOP_H
#define LATTE_INTMODOP_H


#include "../Context.h"
#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntModOp : public Op {
private:
    static llvm::Value *modInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntModOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), modInts(ctx, lInt, rInt)) { }
};


#endif //LATTE_INTMODOP_H
