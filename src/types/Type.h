//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_TYPE_H
#define TESTLLVM_TYPE_H


#include <string>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>

#include "../Context.h"

class Type {
private:
    const std::string typeId;
protected:
    explicit Type(const std::string &typeId) : typeId(typeId) { };
public:
    virtual ~Type() = default;

    const static std::string INT_TYPE_ID;
    const static std::string STRING_TYPE_ID;
    const static std::string BOOLEAN_TYPE_ID;
    const static std::string VOID_TYPE_ID;

    // Works for all non-named types
    virtual bool operator== (const Type& rhs) const { return this->typeId == rhs.typeId; }
    const std::string &getTypeId() const { return typeId; }
    virtual llvm::Type* getLlvmType(Context *ctx) = 0;

    virtual bool isNamedType() const { return false; }
    virtual bool isFunctionType() const { return false; }
    virtual bool isClass() const { return false; }
    virtual bool isTypeComplete() const { return true; }
};

namespace std {
    /* Type will be used in TypeRegistry only, and in TypeRegistry we follow
     * the invariant, that there won't be duplicate type names. Thanks to that
     * invariant, we can use typeId string hash for Type class hash. */
    template<> struct hash<Type>
    {
        using result_type = std::size_t;
        result_type operator()(const Type& c)
        {
            return std::hash<std::string>{}(c.getTypeId());
        }
    };
}

#endif //TESTLLVM_TYPE_H
