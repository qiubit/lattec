#include <iostream>
#include <vector>

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/NoFolder.h>
#include <unordered_set>

#include "antlr4-runtime.h"

#include "parser/LatteLexer.h"
#include "parser/LatteParser.h"
#include "parser/LatteErrorListener.h"

#include "Context.h"
#include "registries/TypeRegistry.h"
#include "scopes/GlobalScope.h"
#include "visitors/GlobalScopeVisitor.h"
#include "operations/NewOp.h"
#include "operations/IntNegOp.h"
#include "operations/BooleanNotOp.h"
#include "operations/TypedNullOp.h"
#include "operations/IntDivOp.h"
#include "operations/ConstStringOp.h"
#include "operations/ConstIntOp.h"
#include "operations/StringAddOp.h"
#include "operations/IntModOp.h"

int main() {
    TypeRegistry registry;
    ScopeRegistry scopeReg;
    Context ctx;
/*
    llvm::FunctionType *FuncTy =
            llvm::FunctionType::get(llvm::Type::getInt32Ty(*env.getContext()), false);
    llvm::Function *Func =
            llvm::Function::Create(FuncTy, llvm::GlobalValue::ExternalLinkage, "main", env.getModule());
    llvm::BasicBlock *BB =
            llvm::BasicBlock::Create(*env.getContext(), "", Func);
    env.getBuilder()->SetInsertPoint(BB);

    auto Type = llvm::Type::getInt32Ty(*env.getContext());
    std::vector<llvm::Type*> structElts{Type, Type, Type};
    structElts.push_back(FuncTy);
    auto StructTy = llvm::StructType::create(*env.getContext(), structElts, "ziomk");
    auto PtrTy = llvm::PointerType::getInt8PtrTy(*env.getContext());
    auto val = llvm::ConstantInt::get(llvm::IntegerType::get(*env.getContext(), 32), 42, true);

    auto constStruct = env.getBuilder()->CreateAlloca(StructTy);
    auto constPtr = env.getBuilder()->CreateAlloca(PtrTy);

    auto properTy = env.getBuilder()->CreateBitCast(constPtr, llvm::PointerType::get(StructTy, 0));

    env.getBuilder()->CreateStore(Func, constPtr);

    env.getBuilder()->CreateStore(constStruct, properTy);


    env.getBuilder()->CreateRet(val);

    env.getModule()->print(llvm::outs(), nullptr);

    std::unordered_set<ClassMetadata> s;
    ClassMetadata h("hello");
    ClassMetadata w("world");
    ClassMetadata k("hello");

    s.insert(h);
    s.insert(w);
*/
    antlr4::ANTLRInputStream input(std::cin);
    LatteLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    LatteErrorListener errorListener;
    lexer.removeErrorListeners();
    lexer.addErrorListener(&errorListener);

    tokens.fill();
    if (errorListener.getErrorCatched()) {
        std::cerr << "ERROR" << std::endl;
        errorListener.printErrors();
        std::cerr << "Lexer error: couldn't continue" << std::endl;
        return 1;
    }

    LatteParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);
    antlr4::tree::ParseTree *tree = parser.program();
    if (errorListener.getErrorCatched()) {
        std::cerr << "ERROR" << std::endl;
        errorListener.printErrors();
        std::cerr << "Parser error: couldn't continue" << std::endl;
        return 1;
    }


    IntType *intType = registry.getIntType();
    VoidType *voidType = registry.getVoidType();
    StringType *stringType = registry.getStringType();
    BytePtrType *bytePtrType = registry.getBytePtrType();

    GlobalScope globalScope(&ctx, &registry, &scopeReg);

    // Declare runtime
    globalScope.declareFunction("malloc", bytePtrType, std::vector<Type *>{intType});
    globalScope.defineFunction("malloc");
    globalScope.declareFunction("printInt", voidType, std::vector<Type *>{intType});
    globalScope.defineFunction("printInt");
    globalScope.declareFunction("printString", voidType, std::vector<Type *>{stringType});
    globalScope.defineFunction("printString");
    globalScope.declareFunction("error", voidType);
    globalScope.defineFunction("error");
    globalScope.declareFunction("readInt", intType);
    globalScope.defineFunction("readInt");
    globalScope.declareFunction("readString", stringType);
    globalScope.defineFunction("readString");
    globalScope.declareFunction("concatStrings", stringType, std::vector<Type *>{stringType, stringType});
    globalScope.defineFunction("concatStrings");
    globalScope.declareFunction("strcmp", intType, std::vector<Type *>{stringType, stringType});
    globalScope.defineFunction("strcmp");

    GlobalScopeVisitor globalScopeVisitor(&globalScope);
    globalScopeVisitor.visit(tree);

    auto globalScopeVisitorErrors = globalScopeVisitor.getErrors();
    if (globalScopeVisitorErrors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string s : globalScopeVisitorErrors) {
            std::cerr << s << std::endl;
        }
        return 1;
    }

/*
    globalScope.declareFunction("main", registry.getIntType());
    globalScope.defineFunction("main");
    auto parT = globalScope.referenceClass("Class");
    auto classT = globalScope.defineClass("Subclass");
    globalScope.defineClass("Class");
    classT->setParentClass(parT);
    //parT->setParentClass(classT);
*/

    auto errors = globalScope.errorChecks();
    if (errors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string error : errors) {
            std::cerr << error << std::endl;
        }
        return 1;
    }

    // class.in test

    llvm::Function *f = globalScope.getSymbolIdEnvEntry("main")->getEntryFunction();
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*ctx.getContext(), "entry", f);
    ctx.getBuilder()->SetInsertPoint(BB);
    /*
    auto ptrAlloca = ctx.getBuilder()->CreateAlloca(registry.getBytePtrType()->getLlvmType(&ctx));
    auto intAlloca = ctx.getBuilder()->CreateAlloca(registry.getIntType()->getLlvmType(&ctx));
    auto ptr = ctx.getBuilder()->CreateLoad(ptrAlloca, "ptr");
    auto testClass = dynamic_cast<ClassType *>(registry.getType("Test"));
    auto ptrCasted = testClass->bitcastToClassPtr(&ctx, ptr);
    auto one = ctx.getBuilder()->getInt32(1);
    auto nullPtr = llvm::ConstantPointerNull::get(llvm::PointerType::get(testClass->getClassStructType(&ctx), 0));
    auto size = ctx.getBuilder()->CreateGEP(testClass->getClassStructType(&ctx), nullPtr, std::vector<llvm::Value *>{one});
    auto sizeInt = ctx.getBuilder()->CreatePtrToInt(size, registry.getIntType()->getLlvmType(&ctx));
    auto getSize = ctx.getBuilder()->CreateCall(globalScope.getSymbolIdEnvEntry("malloc")->getEntryFunction(), sizeInt);
     */
    auto testClass = dynamic_cast<ClassType *>(registry.getType("Test"));
    auto testClass2 = dynamic_cast<ClassType *>(registry.getType("Test2"));
    auto newOp = NewOp(&ctx, globalScope.getIdEnv(), testClass2);
    /*
    auto oneVal = ctx.getBuilder()->getInt1(true);
    auto testedOp = BooleanNotOp(&ctx, &registry, oneVal);
     */
    auto oneVal = ctx.getBuilder()->getInt32(1);
    auto zeroVal = ctx.getBuilder()->getInt32(0);
    auto testedOp = IntDivOp(&ctx, &registry, oneVal, zeroVal);
    auto stringOp = ConstStringOp(&ctx, &registry, "eniu");
    auto intOp = ConstIntOp(&ctx, &registry, -42);
    auto modOp = IntModOp(&ctx, &registry, oneVal, oneVal);
    ctx.getBuilder()->CreateRet(newOp.getOpVal());

    std::cerr << "OK" << std::endl;

    // globalScope.declareFunction("malloc", std::vector<const std::string>{"size"}, registry.getBytePtrType(), std::vector<Type *>{registry.getIntType()});
    ctx.getModule()->print(llvm::outs(), nullptr);
    return 0;
}