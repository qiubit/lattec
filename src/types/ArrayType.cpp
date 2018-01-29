//
// Created by Pawel Golinski on 29.01.2018.
//

#include "ArrayType.h"

ArrayType::ArrayType(Type *elemType) : Type(elemType->getTypeId() + "[]") {
    this->elemType = elemType;
    if (elemType->isArray())
        throw std::invalid_argument("Cannot create multidimensional array");
}
