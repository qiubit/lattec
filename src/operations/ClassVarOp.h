//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_CLASSVAROP_H
#define LATTE_CLASSVAROP_H


#include "Op.h"
#include "../types/ClassType.h"

class ClassVarOp : public Op {
private:
    static Type *getType(ClassType *classType, const std::string &symbol);
    static llvm::Value *getValue(Context *ctx, ClassType *classType, llvm::Value *classBytePtr, const std::string &symbol);
public:
    ClassVarOp(Context *ctx, ClassType *classType, llvm::Value *classBytePtr, const std::string &symbol)
            : Op(getType(classType, symbol), getValue(ctx, classType, classBytePtr, symbol)) { }
};


#endif //LATTE_CLASSVAROP_H
