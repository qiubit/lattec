//
// Created by Pawel Golinski on 19.01.2018.
//

#ifndef TESTLLVM_CLASSMETADATA_H
#define TESTLLVM_CLASSMETADATA_H

#include <string>
#include <set>
#include <vector>
#include <unordered_map>


class ClassMetadata {
private:
    // Hashing is done based on that string,
    // on the assumption there won't be multiple
    // classes with the same name
    std::string id;
    size_t class_size;
    std::unordered_map<std::string, size_t> nameToMemberIdx;
    std::vector<size_t> members;

public:
    ClassMetadata() = delete;
    ClassMetadata(const std::string &id);

    bool operator==(const ClassMetadata& rhs) const {
        return this->id == rhs.id;
    }

    void addMember(size_t space) {
        members.push_back(space);
    }

    const std::string& getName() const {
        return this->id;
    }
};


namespace std {
    template<> struct hash<ClassMetadata>
    {
        using result_type = std::size_t;
        result_type operator()(const ClassMetadata& c)
        {
            return std::hash<std::string>{}(c.getName());
        }
    };
}

#endif //TESTLLVM_CLASSMETADATA_H
