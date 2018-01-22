//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_BOOLEANANDOP_H
#define LATTE_BOOLEANANDOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class BooleanAndOp : Op {
private:
    static llvm::Value *compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool);

public:
    BooleanAndOp(Context *ctx, TypeRegistry *reg, llvm::Value *lBool, llvm::Value *rBool)
            : Op(reg->getBooleanType(), compareBooleans(ctx, lBool, rBool)) { }
};


#endif //LATTE_BOOLEANANDOP_H
