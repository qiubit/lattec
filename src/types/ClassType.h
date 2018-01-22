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

class ClassType : public NamedType {
private:
    ClassType *parentClass = nullptr;
    std::vector<Type *> classMembers;
    std::unordered_map<std::string, size_t> nameToMemberIdx;
    bool defined = false;
public:
    explicit ClassType(const std::string &classId) : NamedType(classId, NamedTypeKind::CLASS) { };
    ~ClassType() override = default;

    void addMember(const std::string &memberName, Type *member);
    Type *getMemberType(const std::string &memberName);
    void setParentClass(ClassType *parent) { parentClass = parent; }
    ClassType *getParentClass() { return parentClass; }
    llvm::PointerType *getLlvmType(Context *ctx) override;
    llvm::StructType *getClassStructType(Context *ctx);
    std::vector<Type *> getClassMembers();
    void defineClass() { defined = true; }
    bool isDefined() const { return defined; }
    bool isTypeComplete() const override { return isDefined(); }

    // Needed for accessing class members
    llvm::Value *bitcastToClassPtr(Context *ctx, llvm::Value *bytePtr);
};


#endif //TESTLLVM_CLASSTYPE_H
