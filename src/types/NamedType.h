//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_NAMEDTYPE_H
#define TESTLLVM_NAMEDTYPE_H


#include "Type.h"

class NamedType : public Type {
public:
    enum class NamedTypeKind {
        CLASS
    };

    ~NamedType() override = default;

    bool operator== (const Type &rhs) const override;
    bool isNamedType() const override { return true; }
    bool isClass() const override { return this->typeKind == NamedTypeKind::CLASS; }
protected:
    NamedType(const std::string &typeId, NamedTypeKind typeKind)
            : Type(typeId), typeKind(typeKind) { };
private:
    NamedTypeKind typeKind;
};


#endif //TESTLLVM_NAMEDTYPE_H
