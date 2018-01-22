//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTNEQOP_H
#define LATTE_INTNEQOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntNeqOp : public Op {
private:
    static llvm::Value *compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntNeqOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), compareInts(ctx, lInt, rInt)) { }

};


#endif //LATTE_INTNEQOP_H
