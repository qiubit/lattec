//
// Created by Pawel Golinski on 22.01.2018.
//

#include "ClassVarOp.h"


Type *ClassVarOp::getType(ClassType *classType, const std::string &symbol) {
    Type *symbolType = classType->getMemberType(symbol);
    if (symbolType == nullptr)
        throw std::invalid_argument("Symbol \"" + symbol + "\" is not defined");
    return symbolType;
}

llvm::Value *ClassVarOp::getValue(Context *ctx, ClassType *classType, llvm::Value *classBytePtr, const std::string &symbol) {
    auto classPtr = classType->bitcastToClassPtr(ctx, classBytePtr);
    // TODO: valid cast?
    uint32_t memberIdx = (uint32_t) classType->getMemberOffset(symbol);
    auto valPtr = ctx->getBuilder()->CreateGEP(
            classType->getClassStructType(ctx),
            classPtr,
            std::vector<llvm::Value *>{ctx->getBuilder()->getInt32(0), ctx->getBuilder()->getInt32(memberIdx)}
    );
    return ctx->getBuilder()->CreateLoad(valPtr);
}
