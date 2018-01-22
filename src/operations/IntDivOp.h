//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_INTDIVOP_H
#define LATTE_INTDIVOP_H


#include <llvm/IR/Value.h>
#include "../Context.h"
#include "../registries/TypeRegistry.h"
#include "Op.h"

class IntDivOp : public Op {
private:
    static llvm::Value  *divInts(Context *ctx, llvm::Value *lInt, llvm::Value *rInt);

public:
    IntDivOp(Context *ctx, TypeRegistry *reg, llvm::Value *lInt, llvm::Value *rInt)
            : Op(reg->getIntType(), divInts(ctx, lInt, rInt)) { }
};


#endif //LATTE_INTDIVOP_H
