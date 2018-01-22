//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_BOOLEANNEQOP_H
#define LATTE_BOOLEANNEQOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class BooleanNeqOp : Op {
private:
    static llvm::Value *compareBooleans(Context *ctx, llvm::Value *lBool, llvm::Value *rBool);

public:
    BooleanNeqOp(Context *ctx, TypeRegistry *reg, llvm::Value *lBool, llvm::Value *rBool)
            : Op(reg->getBooleanType(), compareBooleans(ctx, lBool, rBool)) { }
};


#endif //LATTE_BOOLEANNEQOP_H
