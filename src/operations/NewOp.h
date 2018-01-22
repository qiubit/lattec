//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_NEWOP_H
#define LATTE_NEWOP_H


#include "Op.h"
#include "../types/ClassType.h"
#include "../registries/TypeRegistry.h"


// TODO: Virtual functions override
class NewOp : public Op {
private:
    static llvm::Value *createNewObject(Context *ctx, ClassType *classType);
public:
    NewOp(Context *ctx, ClassType *classType)
            : Op(classType, createNewObject(ctx, classType)) { }
};


#endif //LATTE_NEWOP_H
