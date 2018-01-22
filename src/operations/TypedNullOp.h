//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_TYPEDNULLOP_H
#define LATTE_TYPEDNULLOP_H


#include "Op.h"
#include "../registries/TypeRegistry.h"

class TypedNullOp : public Op {
private:
    static llvm::Value *getNullPtr(Context *ctx, TypeRegistry *reg);

public:
    TypedNullOp(Context *ctx, TypeRegistry *reg, ClassType *classType)
            : Op(classType, getNullPtr(ctx, reg)) { }
};


#endif //LATTE_TYPEDNULLOP_H
