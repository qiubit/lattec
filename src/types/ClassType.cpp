//
// Created by Pawel Golinski on 20.01.2018.
//

#include "ClassType.h"
#include "FunctionType.h"


void ClassType::addMember(const std::string &memberName, Type *member) {
    localClassMembers.push_back(member);
    localNameToMemberIdx[memberName] = localClassMembers.size() - 1;
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
    ret.insert(ret.end(), this->localClassMembers.begin(), this->localClassMembers.end());
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

Type *ClassType::getLocalMemberType(const std::string &memberName) {
    if (localNameToMemberIdx.find(memberName) != localNameToMemberIdx.end()) {
        size_t idx = localNameToMemberIdx[memberName];
        return localClassMembers[idx];
    }
    return nullptr;
}

llvm::Value *ClassType::allocateClass(Context *ctx) {
    auto mallocFun = ctx->getModule()->getFunction("malloc");
    auto nullPtr = llvm::ConstantPointerNull::get(llvm::PointerType::get(getClassStructType(ctx), 0));
    auto oneInt = ctx->getBuilder()->getInt32(1);
    auto classSize = ctx->getBuilder()->CreateGEP(getClassStructType(ctx), nullPtr, std::vector<llvm::Value *>{oneInt});
    auto classSizeInt = ctx->getBuilder()->CreatePtrToInt(classSize, llvm::IntegerType::getInt32Ty(*ctx->getContext()));
    return ctx->getBuilder()->CreateCall(mallocFun, classSizeInt);
}

void ClassType::initializeMemberData() {
    if (!memberDataInitialized) {
        std::unordered_map<std::string, int> parentOffsets;
        std::unordered_map<std::string, Type *> parentTypes;
        std::unordered_map<std::string, std::vector<int>> allParentOffsets;

        if (parentClass != nullptr) {
            parentClass->initializeMemberData();
            size = parentClass->size;
            parentOffsets = parentClass->memberOffsets;
            parentTypes = parentClass->memberTypes;
            allParentOffsets = parentClass->allMemberOffsets;
        }

        memberTypes = parentTypes;
        memberOffsets = parentOffsets;
        allMemberOffsets = allParentOffsets;

        // Iterate over local members to check if they are consistent and merge them with "global"
        for (auto it : localNameToMemberIdx) {
            // Fetch local member metadata
            std::string memberName = it.first;
            size_t memberIdx = it.second;
            Type *memberType = localClassMembers[memberIdx];

            // If we're overwriting a function, verify its signature
            if (parentTypes.find(memberName) != parentTypes.end()) {
                FunctionType *parentType = dynamic_cast<FunctionType *>(parentTypes[memberName]);
                FunctionType *memberFunType = dynamic_cast<FunctionType *>(memberType);
                if (parentType != nullptr) parentType->setThisFlag();
                if (memberFunType != nullptr) memberFunType->setThisFlag();
                if (parentType != nullptr && (memberFunType == nullptr || !(*memberFunType == *parentType))) {
                    throw std::invalid_argument(
                            "Wrong virtual function override for function \"" + memberName + "\" detected in class \"" + this->getTypeId() + "\""
                    );
                }
            }

            memberTypes[memberName] = memberType;
            memberOffsets[memberName] = size + memberIdx;
            allMemberOffsets[memberName].push_back(size + memberIdx);
        }

        size += localNameToMemberIdx.size();
        memberDataInitialized = true;
    }
}

int ClassType::getMemberOffset(const std::string &memberName) {
    if (!memberDataInitialized)
        initializeMemberData();
    if (memberOffsets.find(memberName) != memberOffsets.end())
        return memberOffsets[memberName];
    return -1;
}

Type *ClassType::getMemberType(const std::string &memberName) {
    if (!memberDataInitialized)
        initializeMemberData();
    if (memberTypes.find(memberName) != memberTypes.end())
        return memberTypes[memberName];
    return nullptr;
}

// TODO: quadratic... and messy :<
void ClassType::overwriteVirtualFunctions(Context *ctx, IdEnv *functionEnv, llvm::Value *classBytePtr) {
    // Nothing to do if no parent
    if (parentClass != nullptr) {
        parentClass->overwriteVirtualFunctions(ctx, functionEnv, classBytePtr);
        auto classStructType = getClassStructType(ctx);
        auto classPtr = bitcastToClassPtr(ctx, classBytePtr);
        for (auto &it : memberOffsets) {
            const std::string &memberName = it.first;
            int memberOffset = it.second;
            Type *memberType = memberTypes[memberName];

            if (localNameToMemberIdx.find(memberName) != localNameToMemberIdx.end()) {
                if (memberType->isFunctionType()) {
                    std::vector<int> allMemberOffsets = this->allMemberOffsets[memberName];
                    IdEnvEntry &envEntry = functionEnv->getEnvEntryForId(this->getTypeId() + "." + memberName);
                    llvm::Function *myFunction = envEntry.getEntryFunction();
                    for (auto offset : allMemberOffsets) {
                        auto functionPtr = ctx->getBuilder()->CreateGEP(
                                classStructType,
                                classPtr,
                                std::vector<llvm::Value *>{ctx->getBuilder()->getInt32(0), ctx->getBuilder()->getInt32(offset)}
                        );
                        ctx->getBuilder()->CreateStore(myFunction, functionPtr);
                    }
                }
            }
        }
    }
}
