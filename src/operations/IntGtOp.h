//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTGTOP_H
#define LATTE_INTGTOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntGtOp : public Op {
private:
    static llvm::Value *compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntGtOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), compareInts(ctx, lInt, rInt)) { }

};


#endif //LATTE_INTGTOP_H
