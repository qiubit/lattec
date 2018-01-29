//
// Created by Pawel Golinski on 29.01.2018.
//

#include "ArrayType.h"
#include "ClassType.h"


llvm::Type *ArrayType::getLlvmType(Context *ctx) {
    return ctx->getBuilder()->getInt8PtrTy(0);
}

ArrayType::ArrayType(Type *elemType) : Type(elemType->getTypeId() + "[]") {
    this->elemType = elemType;
    if (elemType->isArray())
        throw std::invalid_argument("Cannot create multidimensional array");
}

llvm::Value *ArrayType::getElem(Context *ctx, llvm::Value *arrayPtr, llvm::Value *idx) {
    llvm::Type *elemTypeLlvm = elemType->getLlvmType(ctx);
    llvm::Value *intoMemberPtr = ctx->getBuilder()->CreateGEP(
            elemTypeLlvm,
            ctx->getBuilder()->CreateBitCast(arrayPtr, llvm::PointerType::get(elemTypeLlvm, 0)),
            std::vector<llvm::Value *>{idx}
    );
    return ctx->getBuilder()->CreateLoad(intoMemberPtr);
}

llvm::Value *ArrayType::getElemPtr(Context *ctx, llvm::Value *arrayPtr, llvm::Value *idx) {
    llvm::Type *elemTypeLlvm = elemType->getLlvmType(ctx);
    llvm::Value *intoMemberPtr = ctx->getBuilder()->CreateGEP(
            elemTypeLlvm,
            ctx->getBuilder()->CreateBitCast(arrayPtr, llvm::PointerType::get(elemTypeLlvm, 0)),
            std::vector<llvm::Value *>{idx}
    );
    return intoMemberPtr;
}

llvm::Value *ArrayType::getLength(Context *ctx, llvm::Value *arrayPtr) {
    llvm::Type *t = ctx->getBuilder()->getInt32Ty();
    llvm::PointerType *ptrT = llvm::PointerType::get(t, 0);
    llvm::Value *bitcastPtr = ctx->getBuilder()->CreateBitCast(arrayPtr, ptrT);
    auto lenPtr = ctx->getBuilder()->CreateGEP(
            t,
            bitcastPtr,
            std::vector<llvm::Value *>{ctx->getBuilder()->getInt32(-1)}
    );
    return ctx->getBuilder()->CreateLoad(lenPtr);
}

llvm::Value *ArrayType::allocateArray(Context *ctx, llvm::Value *size) {
    llvm::Value *nullElemPtr = llvm::ConstantPointerNull::get(llvm::PointerType::get(elemType->getLlvmType(ctx), 0));
    llvm::Value *nullPlusOne = ctx->getBuilder()->CreateGEP(
            elemType->getLlvmType(ctx),
            nullElemPtr,
            std::vector<llvm::Value *>{ctx->getBuilder()->getInt32(1)}
    );
    llvm::Value *elemSize = ctx->getBuilder()->CreatePtrToInt(nullPlusOne, ctx->getBuilder()->getInt32Ty());
    llvm::Value *arraySize = ctx->getBuilder()->CreateMul(size, elemSize);
    llvm::Value *lenSize = ctx->getBuilder()->getInt32(4);
    llvm::Function *malloc = ctx->getModule()->getFunction("malloc");
    auto memoryPtr =
            ctx->getBuilder()->CreateCall(malloc, std::vector<llvm::Value *>{ctx->getBuilder()->CreateAdd(arraySize, lenSize)});
    auto lenPtr = ctx->getBuilder()->CreateBitCast(memoryPtr, llvm::PointerType::get(ctx->getBuilder()->getInt32Ty(), 0));
    ctx->getBuilder()->CreateStore(size, lenPtr);
    return ctx->getBuilder()->CreateGEP(
            ctx->getBuilder()->getInt8Ty(),
            memoryPtr,
            std::vector<llvm::Value *>{ctx->getBuilder()->getInt32(4)}
    );

}
