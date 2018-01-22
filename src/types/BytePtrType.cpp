//
// Created by Pawel Golinski on 21.01.2018.
//

#include "BytePtrType.h"

BytePtrType::BytePtrType() : Type("") { }

bool BytePtrType::operator==(const Type &rhs) const {
    try {
        auto &castTest = dynamic_cast<const BytePtrType&>(rhs);
    } catch (std::bad_cast &e) {
        return false;
    }
    return true;
}

llvm::PointerType *BytePtrType::getLlvmType(Context *ctx) {
    return llvm::PointerType::getInt8PtrTy(*ctx->getContext());
}
