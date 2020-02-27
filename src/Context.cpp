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

llvm::Value *Context::getStringGlobal(const std::string &str) {
    auto strGlobalType = llvm::ArrayType::get(llvm::IntegerType::get(*this->llvmCtx, 8), str.length() + 1);
    if (stringGlobals.find(str) == stringGlobals.end()) {
        auto llvmStr = llvm::ConstantDataArray::getString(*this->llvmCtx, str);
        // TODO: possible memleak
        llvm::GlobalVariable *strGlobal =
                new llvm::GlobalVariable(*this->llvmModule, strGlobalType, true, llvm::GlobalValue::InternalLinkage, llvmStr);
        this->stringGlobals[str] = strGlobal;
    }
    auto globalStrPtr = this->llvmBuilder->CreateGEP(
            strGlobalType,
            stringGlobals[str],
            std::vector<llvm::Value *>{llvmBuilder->getInt32(0), llvmBuilder->getInt32(0)}
    );
    if (str == "") {
        return globalStrPtr;
    } else {
        llvm::Function *stringGetter = getModule()->getFunction("getString");
        return getBuilder()->CreateCall(stringGetter, globalStrPtr);
    }
}
