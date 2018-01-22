//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_TYPEREGISTRY_H
#define TESTLLVM_TYPEREGISTRY_H


#include <unordered_map>
#include <string>

#include "../types/Type.h"
#include "../types/IntType.h"
#include "../types/ClassType.h"
#include "../types/BooleanType.h"
#include "../types/FunctionType.h"
#include "../types/BytePtrType.h"
#include "../types/VoidType.h"
#include "../types/StringType.h"

class TypeRegistry {
private:
    std::unordered_map<std::string, std::unique_ptr<Type>> registeredNamedTypes;
    std::vector<std::unique_ptr<FunctionType>> functionDefs;
    std::unique_ptr<BytePtrType> bytePtrType;
public:
    TypeRegistry();
    void registerNamedType(const std::string &typeId, NamedType::NamedTypeKind requestedType = NamedType::NamedTypeKind::CLASS);
    Type *getType(const std::string &typeId);
    FunctionType *getFunctionType(Type *returnType,
                                  std::vector<Type *> &argTypes);
    FunctionType *getFunctionType(Type *returnType);
    BytePtrType *getBytePtrType();
    IntType *getIntType();
    BooleanType *getBooleanType();
    VoidType *getVoidType();
    StringType *getStringType();
    std::vector<std::pair<std::string, Type *>> getNamedTypes();
    bool typeExits(const std::string &typeId);
};

#endif //TESTLLVM_TYPEREGISTRY_H
