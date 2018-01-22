//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_CONSTINTOP_H
#define LATTE_CONSTINTOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class ConstIntOp : public Op {
private:
    static llvm::Value *generateConstInt(Context *ctx, int val);

public:
    ConstIntOp(Context *ctx, TypeRegistry *reg, int val)
            : Op(reg->getIntType(), generateConstInt(ctx, val)) { }
};


#endif //LATTE_CONSTINTOP_H
