//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTEQOP_H
#define LATTE_INTEQOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntEqOp : public Op {
private:
    static llvm::Value *compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntEqOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), compareInts(ctx, lInt, rInt)) { }

};


#endif //LATTE_INTEQOP_H
