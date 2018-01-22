//
// Created by Pawel Golinski on 20.01.2018.
//

#include <stdexcept>

#include "FunctionType.h"


static void FunctionTypeArgumentCheck(Type *retType, std::vector<Type *> &argsType)
{
    if (retType->isFunctionType())
        throw std::invalid_argument("FunctionType with FunctionType return argument not supported");
    for (Type *argType : argsType) {
        if (argType->isFunctionType())
            throw std::invalid_argument("FunctionType with FunctionType input parameter not supported");
    }
}

FunctionType::FunctionType(Type *retType, std::vector<Type *> &argsType) : Type("") {
    FunctionTypeArgumentCheck(retType, argsType);
    this->retType = retType;
    this->argsType = argsType;
}

FunctionType::FunctionType(Type *retType, std::vector<Type *> &&argsType) : Type("") {
    FunctionTypeArgumentCheck(retType, argsType);
    this->retType = retType;
    this->argsType = std::move(argsType);
}

bool FunctionType::operator==(const Type &rhs) const {
    bool equal;
    try {
        auto &rhsFunType = dynamic_cast<const FunctionType &>(rhs);
        equal = (rhsFunType.retType == retType && rhsFunType.argsType == argsType);
    } catch (std::bad_cast &e) {
        equal = false;
    }
    return equal;
}

llvm::Type *FunctionType::getLlvmType(Context *ctx) {
    return inferLlvmType(ctx);
}

llvm::FunctionType *FunctionType::inferLlvmType(Context *ctx) {
    if (this->inferredLlvmTypes.find(ctx->getContext()) == this->inferredLlvmTypes.end()) {
        llvm::Type *returnType;
        std::vector<llvm::Type *> argsType;

        returnType = this->retType->getLlvmType(ctx);
        for (Type *argType : this->argsType) {
            argsType.push_back(argType->getLlvmType(ctx));
        }

        llvm::FunctionType *ret =
                llvm::FunctionType::get(returnType, argsType, false);
        this->inferredLlvmTypes[ctx->getContext()] = ret;
        return ret;
    }
    return this->inferredLlvmTypes.find(ctx->getContext())->second;
}

llvm::Function *FunctionType::generateFunction(Context *ctx, const std::string &name) {
    auto fType = inferLlvmType(ctx);
    if (fType != nullptr) {
        llvm::Function *f = llvm::Function::Create(fType, llvm::GlobalValue::ExternalLinkage, name, ctx->getModule());
        if (f != nullptr)
            f->setCallingConv(llvm::CallingConv::C);
        return f;
    }
    return nullptr;
}

const Type *FunctionType::getRetType() {
    return retType;
}

const std::vector<Type *> FunctionType::getArgsType() {
    return argsType;
}
