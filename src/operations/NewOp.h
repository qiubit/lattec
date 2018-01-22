//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_NEWOP_H
#define LATTE_NEWOP_H


#include "Op.h"
#include "../types/ClassType.h"
#include "../registries/TypeRegistry.h"


class NewOp : public Op {
private:
    static llvm::Value *createNewObject(Context *ctx, IdEnv *functionEnv, ClassType *classType);
public:
    NewOp(Context *ctx, IdEnv *functionEnv, ClassType *classType)
            : Op(classType, createNewObject(ctx, functionEnv, classType)) { }
};


#endif //LATTE_NEWOP_H
