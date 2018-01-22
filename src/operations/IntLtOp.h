//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTLTOP_H
#define LATTE_INTLTOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class IntLtOp : public Op {
private:
    static llvm::Value *compareInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntLtOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), compareInts(ctx, lInt, rInt)) { }

};


#endif //LATTE_INTLTOP_H
