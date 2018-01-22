//
// Created by Pawel Golinski on 20.01.2018.
//

#ifndef TESTLLVM_ENVIRONMENT_H
#define TESTLLVM_ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <stdexcept>

#include "IdEnvEntry.h"
#include "types/FunctionType.h"
#include "types/ClassType.h"

class IdEnv {
private:
    std::unordered_map<std::string, std::unique_ptr<IdEnvEntry>> envMap;
public:
    bool envEntryExists(const std::string &id);
    IdEnvEntry &getEnvEntryForId(const std::string &id);
    IdEnvEntry &addEnvEntryForId(const std::string &id, Type *t);
    std::vector<std::pair<std::string, IdEnvEntry *>> getEnvEntries();
};


#endif //TESTLLVM_ENVIRONMENT_H
