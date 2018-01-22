//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_BOOLNOTOP_H
#define LATTE_BOOLNOTOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class BooleanNotOp : public Op {
private:
    static llvm::Value *negateBoolean(Context *ctx, llvm::Value *val);
public:
    BooleanNotOp(Context *ctx, TypeRegistry *reg, llvm::Value *val)
            : Op(reg->getBooleanType(), negateBoolean(ctx, val)) { };
};


#endif //LATTE_BOOLNOTOP_H
