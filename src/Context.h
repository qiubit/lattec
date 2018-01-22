//
// Created by Pawel Golinski on 18.01.2018.
//

#ifndef TESTLLVM_LLVMENV_H
#define TESTLLVM_LLVMENV_H

#include <memory>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

class Context {
private:
    std::unique_ptr<llvm::LLVMContext> llvmCtx;
    std::unique_ptr<llvm::IRBuilder<>> llvmBuilder;
    std::unique_ptr<llvm::Module> llvmModule;
public:
    Context();
    llvm::LLVMContext *getContext();
    llvm::IRBuilder<> *getBuilder();
    llvm::Module *getModule();
};

#endif //TESTLLVM_LLVMENV_H
