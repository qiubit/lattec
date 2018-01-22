//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_NEGOP_H
#define LATTE_NEGOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntNegOp : public Op {
private:
    static llvm::Value *negateInt(Context *ctx, llvm::Value *val);
public:
    IntNegOp(Context *ctx, TypeRegistry *reg, llvm::Value *val)
            : Op(reg->getIntType(), negateInt(ctx, val)) { };
};


#endif //LATTE_NEGOP_H
