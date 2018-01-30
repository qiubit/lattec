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
#include "visitors/FunctionScopeVisitor.h"
#include "visitors/CodegenVisitor.h"

int main() {
    TypeRegistry registry;
    ScopeRegistry scopeReg;
    Context ctx;

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
    globalScope.declareFunction("getString", stringType, std::vector<Type *>{stringType});
    globalScope.defineFunction("getString");
    globalScope.declareFunction("refString", voidType, std::vector<Type *>{stringType});
    globalScope.defineFunction("refString");
    globalScope.declareFunction("derefString", voidType, std::vector<Type *>{stringType});
    globalScope.defineFunction("derefString");

    GlobalScopeVisitor globalScopeVisitor(&globalScope);
    globalScopeVisitor.visit(tree);

    auto globalScopeVisitorErrors = globalScopeVisitor.getErrors();
    if (globalScopeVisitorErrors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string &s : globalScopeVisitorErrors) {
            std::cerr << s << std::endl;
        }
        return 1;
    }

    auto errors = globalScope.errorChecks();
    if (errors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string &error : errors) {
            std::cerr << error << std::endl;
        }
        return 1;
    }

    FunctionScopeVisitor functionScopeVisitor{&globalScope, &scopeReg};
    functionScopeVisitor.visit(tree);

    auto functionScopeVisitorErrors = functionScopeVisitor.getErrors();
    if (functionScopeVisitorErrors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string &s : functionScopeVisitorErrors) {
            std::cerr << s << std::endl;
        }
        return 1;
    }

    CodegenVisitor codegenVisitor{
            &ctx, &registry, &globalScope, functionScopeVisitor.getExprTypes(),
            functionScopeVisitor.getStmtScopes(), &scopeReg
    };
    codegenVisitor.visit(tree);

    auto codegenVisitorErrors = codegenVisitor.getErrors();
    if (codegenVisitorErrors.size() > 0) {
        std::cerr << "ERROR" << std::endl;
        for (std::string &s : codegenVisitorErrors) {
            std::cerr << s << std::endl;
        }
        return 1;
    }

    std::cerr << "OK" << std::endl;

    // globalScope.declareFunction("malloc", std::vector<const std::string>{"size"}, registry.getBytePtrType(), std::vector<Type *>{registry.getIntType()});
    ctx.getModule()->print(llvm::outs(), nullptr);
    return 0;
}