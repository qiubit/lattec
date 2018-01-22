//
// Created by Pawel Golinski on 20.01.2018.
//

#include "IdEnv.h"

bool IdEnv::envEntryExists(const std::string &id) {
    return envMap.find(id) != envMap.end();
}

IdEnvEntry &IdEnv::getEnvEntryForId(const std::string &id) {
    if (envMap.find(id) == envMap.end())
        throw std::invalid_argument("No env entry with given id " + id);
    return *envMap.find(id)->second;
}

IdEnvEntry &IdEnv::addEnvEntryForId(const std::string &id, Type *t) {
    if (envMap.find(id) != envMap.end())
        throw std::invalid_argument("EnvEntry for given id " + id + " already added");
    envMap[id] = std::make_unique<IdEnvEntry>(id, t);
    return *envMap[id];
}

std::vector<std::pair<std::string, IdEnvEntry *>> IdEnv::getEnvEntries() {
    std::vector<std::pair<std::string, IdEnvEntry *>> ret;
    for (auto &it : envMap) {
        ret.push_back(std::make_pair(it.first, it.second.get()));
    }
    return ret;
}
