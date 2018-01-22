//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_CONSTSTRINGOP_H
#define LATTE_CONSTSTRINGOP_H


#include <llvm/IR/Value.h>
#include "../Context.h"
#include "../registries/TypeRegistry.h"
#include "Op.h"

class ConstStringOp : public Op {
private:
    static llvm::Value *generateConstString(Context *ctx, const std::string &str);

public:
    ConstStringOp(Context *ctx, TypeRegistry *reg, const std::string &str)
            : Op(reg->getStringType(), generateConstString(ctx, str)) { }
};


#endif //LATTE_CONSTSTRINGOP_H
