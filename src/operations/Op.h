//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_OP_H
#define LATTE_OP_H


#include "../types/Type.h"

class Op {
private:
    Type *opType;
    llvm::Value *opVal;
protected:
    Op(Type *opType, llvm::Value *opVal) : opType(opType), opVal(opVal) { }
public:
    Type *getOpType() { return opType; }
    llvm::Value *getOpVal() { return opVal; }
};


#endif //LATTE_OP_H
