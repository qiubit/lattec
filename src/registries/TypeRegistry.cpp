//
// Created by Pawel Golinski on 20.01.2018.
//

#include "TypeRegistry.h"

TypeRegistry::TypeRegistry() {
    this->registeredNamedTypes[Type::INT_TYPE_ID] = std::make_unique<IntType>();
    this->registeredNamedTypes[Type::BOOLEAN_TYPE_ID] = std::make_unique<BooleanType>();
    this->registeredNamedTypes[Type::VOID_TYPE_ID] = std::make_unique<VoidType>();
    this->registeredNamedTypes[Type::STRING_TYPE_ID] = std::make_unique<StringType>();
    bytePtrType = std::make_unique<BytePtrType>();
}

void TypeRegistry::registerNamedType(const std::string &typeId, NamedType::NamedTypeKind requestedType) {
    // If typeId is not found, then we're surely registering new named type
    if (registeredNamedTypes.find(typeId) == registeredNamedTypes.end()) {
        if (requestedType != NamedType::NamedTypeKind::CLASS)
            throw std::invalid_argument("Cannot initialized named type of kind different than CLASS");
        std::unique_ptr<Type> newType = std::make_unique<ClassType>(typeId);
        registeredNamedTypes.insert(std::pair<std::string, std::unique_ptr<Type>>(typeId, std::move(newType)));
    }
}

Type *TypeRegistry::getType(const std::string &typeId) {
    if (registeredNamedTypes.find(typeId) != registeredNamedTypes.end()) {
        return registeredNamedTypes.find(typeId)->second.get();
    }
    return nullptr;
}

FunctionType *TypeRegistry::getFunctionType(Type *returnType, std::vector<Type *> &argTypes) {
    this->functionDefs.push_back(std::make_unique<FunctionType>(returnType, argTypes));
    return this->functionDefs.back().get();
}

FunctionType *TypeRegistry::getFunctionType(Type *returnType) {
    this->functionDefs.push_back(std::make_unique<FunctionType>(returnType, std::vector<Type *>()));
    return this->functionDefs.back().get();
}

BytePtrType *TypeRegistry::getBytePtrType() {
    return bytePtrType.get();
}

IntType *TypeRegistry::getIntType() {
    return dynamic_cast<IntType *>(this->registeredNamedTypes[Type::INT_TYPE_ID].get());
}

BooleanType *TypeRegistry::getBooleanType() {
    return dynamic_cast<BooleanType *>(this->registeredNamedTypes[Type::BOOLEAN_TYPE_ID].get());
}

std::vector<std::pair<std::string, Type *>> TypeRegistry::getNamedTypes() {
    auto ret = std::vector<std::pair<std::string, Type *>>();
    for (auto &it : registeredNamedTypes) {
        ret.push_back(std::make_pair(it.first, it.second.get()));
    }
    return ret;
}

VoidType *TypeRegistry::getVoidType() {
    return dynamic_cast<VoidType *>(this->registeredNamedTypes[Type::VOID_TYPE_ID].get());
}

StringType *TypeRegistry::getStringType() {
    return dynamic_cast<StringType *>(this->registeredNamedTypes[Type::STRING_TYPE_ID].get());
}

bool TypeRegistry::typeExits(const std::string &typeId) {
    return registeredNamedTypes.find(typeId) != registeredNamedTypes.end();
}

