//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTGEQOP_H
#define LATTE_INTGEQOP_H


#include "../registries/TypeRegistry.h"
#include "Op.h"

class IntGeqOp : public Op {
private:
    static llvm::Value *compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntGeqOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), compareInts(ctx, lInt, rInt)) { }

};


#endif //LATTE_INTGEQOP_H
