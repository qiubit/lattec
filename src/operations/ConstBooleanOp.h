//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_CONSTBOOLEANOP_H
#define LATTE_CONSTBOOLEANOP_H


#include "../Context.h"
#include "../registries/TypeRegistry.h"
#include "Op.h"

class ConstBooleanOp : public Op {
private:
    static llvm::Value *generateConstBoolean(Context *ctx, bool val);

public:
    ConstBooleanOp(Context *ctx, TypeRegistry *reg, int val)
            : Op(reg->getBooleanType(), generateConstBoolean(ctx, val)) { }
};


#endif //LATTE_CONSTBOOLEANOP_H
