//
// Created by Pawel Golinski on 29.01.2018.
//

#ifndef LATTE_ARRAYTYPE_H
#define LATTE_ARRAYTYPE_H


#include "Type.h"

class ArrayType : public Type {
private:
    Type *elemType;

public:
    ArrayType(Type *elemType);

    bool isArray() const override { return true; }
};


#endif //LATTE_ARRAYTYPE_H
