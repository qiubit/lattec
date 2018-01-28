//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_CLASSTYPE_H
#define TESTLLVM_CLASSTYPE_H

#include <vector>
#include <llvm/IR/Type.h>
#include <llvm/IR/IRBuilder.h>
#include <unordered_map>

#include "NamedType.h"
#include "../IdEnv.h"

class IdEnv;

class ClassType : public NamedType {
private:
    ClassType *parentClass = nullptr;
    std::vector<Type *> localClassMembers;
    std::unordered_map<std::string, size_t> localNameToMemberIdx;

    bool defined = false;

    /* member data, initialized after entire class hierarchy is fixed */
    bool memberDataInitialized = false;

    int size = 0;
    std::unordered_map<std::string, int> memberOffsets;
    std::unordered_map<std::string, Type *> memberTypes;
    std::unordered_map<std::string, std::vector<int>> allMemberOffsets;
    /* end of member data */

public:
    explicit ClassType(const std::string &classId) : NamedType(classId, NamedTypeKind::CLASS) { };
    ~ClassType() override = default;

    void addMember(const std::string &memberName, Type *member);
    // Ignores class hierarchy
    Type *getLocalMemberType(const std::string &memberName);
    void setParentClass(ClassType *parent) { parentClass = parent; }
    ClassType *getParentClass() { return parentClass; }
    std::vector<Type *> getClassMembers();
    void defineClass() { defined = true; }
    bool isDefined() const { return defined; }
    bool isTypeComplete() const override { return isDefined(); }
    llvm::Value *allocateClass(Context *ctx);

    // These functions should be called only after hierarchy is final
    int getMemberOffset(const std::string &memberName);
    Type *getMemberType(const std::string &memberName);

    llvm::PointerType *getLlvmType(Context *ctx) override;
    llvm::StructType *getClassStructType(Context *ctx);
    llvm::Value *bitcastToClassPtr(Context *ctx, llvm::Value *bytePtr);
    llvm::Value *getMemberVariablePtr(Context *ctx, const std::string &symbol, llvm::Value *bytePtr);
    void overwriteVirtualFunctions(Context *ctx, IdEnv *functionEnv, llvm::Value *classBytePtr);

    void initializeMemberData();
};


#endif //TESTLLVM_CLASSTYPE_H
