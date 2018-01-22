//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_VAROP_H
#define LATTE_VAROP_H


#include "Op.h"

class VarOp : public Op {
private:
    static llvm::Value *loadVar(Context *ctx, llvm::Value *varAllocd);
public:
    VarOp(Context *ctx, Type *varType, llvm::Value *varAllocd) :
            Op(varType, loadVar(ctx, varAllocd)) { }
};


#endif //LATTE_VAROP_H
