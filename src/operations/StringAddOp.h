//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_STRINGADDOP_H
#define LATTE_STRINGADDOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class StringAddOp : public Op {
private:
    static llvm::Value *concatStrings(Context *ctx, llvm::Value *lStr, llvm::Value *rStr);
public:
    StringAddOp(Context *ctx, TypeRegistry *reg, llvm::Value *lStr, llvm::Value *rStr)
            : Op(reg->getStringType(), concatStrings(ctx, lStr, rStr)) { }
};


#endif //LATTE_STRINGADDOP_H
