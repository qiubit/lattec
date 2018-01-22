//
// Created by Pawel Golinski on 18.01.2018.
//

#include "Context.h"


Context::Context()
{
    this->llvmCtx = std::make_unique<llvm::LLVMContext>();
    this->llvmBuilder = std::make_unique<llvm::IRBuilder<>>(*this->llvmCtx);
    this->llvmModule = std::make_unique<llvm::Module>("latte.ll", *this->llvmCtx);
}

llvm::LLVMContext* Context::getContext() {
    return this->llvmCtx.get();
}

llvm::IRBuilder<>* Context::getBuilder() {
    return this->llvmBuilder.get();
}

llvm::Module* Context::getModule() {
    return this->llvmModule.get();
}
