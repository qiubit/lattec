//
// Created by Pawel Golinski on 22.01.2018.
//

#ifndef LATTE_SCOPE_H
#define LATTE_SCOPE_H


#include "../IdEnvEntry.h"

class Scope {
public:
    virtual IdEnvEntry *getSymbolIdEnvEntry(const std::string &symbol) = 0;
};


#endif //LATTE_SCOPE_H
