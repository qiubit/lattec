//
// Created by Pawel Golinski on 20.01.2018.
//

#include "NamedType.h"

bool NamedType::operator==(const Type &rhs) const {
    if (rhs.isNamedType()) {
        return Type::operator==(rhs);
    }
    return false;
}
