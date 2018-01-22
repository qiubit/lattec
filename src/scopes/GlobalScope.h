//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_GLOBALSCOPE_H
#define TESTLLVM_GLOBALSCOPE_H

#include <unordered_set>
#include <unordered_map>
#include <llvm/IR/Value.h>
#include <llvm/IR/Function.h>

#include "../IdEnv.h"
#include "../IdEnvEntry.h"
#include "../Context.h"
#include "../types/ClassType.h"
#include "../types/FunctionType.h"
#include "../registries/TypeRegistry.h"

#include "../scopes/ClassScope.h"
#include "../registries/ScopeRegistry.h"
#include "Scope.h"

/* GlobalScope contains top-level funtion
 * definitions and data required to fetch
 * ClassScope for all defined classes */

class ClassScope;
class FunctionScope;
class ScopeRegistry;

class GlobalScope : public Scope {
private:
    Context *ctx;
    TypeRegistry *reg;
    ScopeRegistry *scopeReg;
    IdEnv env;

    // Class scopes get created after calling defineClass()
    std::unordered_map<std::string, ClassScope *> classScopes;
    std::unordered_map<std::string, FunctionScope *> functionScopes;
    std::unordered_set<std::string> classNames;

    std::vector<std::string> checkForUndefinedClasses();
    bool checkForInheritanceCycles();
    bool checkForMain();
    void checkClassHierarchy(std::vector<std::string> &errors);
public:
    explicit GlobalScope(Context *ctx, TypeRegistry *reg, ScopeRegistry *scopeReg) : ctx(ctx), reg(reg), scopeReg(scopeReg) { }

    std::vector<std::string> errorChecks();

    /* These functions will be called by AST visitor,
     * they probably should not know much about LLVM */
    ClassType *referenceClass(const std::string &className);
    ClassType *defineClass(const std::string &className);
    void declareFunction(const std::string &funName, Type *returnType, std::vector<Type *> argTypes);
    void declareFunction(const std::string &funName, Type *returnType);
    void declareClassFunction(const std::string &className, const std::string &funName, Type *returnType, std::vector<Type *> argTypes);
    void defineFunction(const std::string &funName);
    void defineClassFunction(const std::string &className, const std::string &funName);
    void defineClassVariable(const std::string &className, const std::string &varName, Type *t);
    void createFunctionScope(const std::string &funName, const std::vector<std::string> &argNames);

    bool isSymbolDeclared(const std::string &symbol) { return env.envEntryExists(symbol); }
    IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) override;
    IdEnv *getIdEnv();
    TypeRegistry *getTypeRegistry();
    ClassScope *getClassScope(const std::string &classId);
};


#endif //TESTLLVM_GLOBALSCOPE_H
