//
// Created by Pawel Golinski on 20.01.2018.
//

#include "ClassType.h"
#include "FunctionType.h"


void ClassType::addMember(const std::string &memberName, Type *member) {
    classMembers.push_back(member);
    nameToMemberIdx[memberName] = classMembers.size() - 1;
}

llvm::PointerType *ClassType::getLlvmType(Context *ctx) {
    return llvm::Type::getInt8PtrTy(*ctx->getContext());
}


llvm::Value *ClassType::bitcastToClassPtr(Context *ctx, llvm::Value *bytePtr) {
    llvm::StructType *t = getClassStructType(ctx);
    llvm::PointerType *ptrT = llvm::PointerType::get(t, 0);
    return ctx->getBuilder()->CreateBitCast(bytePtr, ptrT);
}

std::vector<Type *> ClassType::getClassMembers() {
    std::vector<Type *> ret{};
    if (this->parentClass != nullptr) {
        auto parentMembers = this->parentClass->getClassMembers();
        ret.insert(ret.end(), parentMembers.begin(), parentMembers.end());
    }
    ret.insert(ret.end(), this->classMembers.begin(), this->classMembers.end());
    return ret;
}

// TODO: Cache result in order to avoid frequent reevaluation
llvm::StructType *ClassType::getClassStructType(Context *ctx) {
    std::vector<Type *> allMemberTypes = getClassMembers();

    std::vector<llvm::Type *> classMembersType;
    for (Type *t : allMemberTypes) {
        FunctionType *ft = dynamic_cast<FunctionType *>(t);
        if (ft != nullptr)
            classMembersType.push_back(llvm::PointerType::get(ft->getLlvmType(ctx), 0));
        else
            classMembersType.push_back(t->getLlvmType(ctx));
    }

    return llvm::StructType::get(*ctx->getContext(), classMembersType);
}

Type *ClassType::getMemberType(const std::string &memberName) {
    if (nameToMemberIdx.find(memberName) != nameToMemberIdx.end()) {
        size_t idx = nameToMemberIdx[memberName];
        return classMembers[idx];
    }
    return nullptr;
}
