//
// Created by Pawel Golinski on 20.01.2018.
//

#include "GlobalScope.h"

ClassType *GlobalScope::referenceClass(const std::string &className) {
    TypeRegistry &registry = *reg;
    if (registry.getType(className) == nullptr) {
        registry.registerNamedType(className, NamedType::NamedTypeKind::CLASS);
    }
    return dynamic_cast<ClassType *>(registry.getType(className));
}

ClassType *GlobalScope::defineClass(const std::string &className) {
    ClassType *ret;
    TypeRegistry &registry = *reg;
    if (registry.getType(className) == nullptr)
        registry.registerNamedType(className, NamedType::NamedTypeKind::CLASS);
    ret = referenceClass(className);
    if (ret == nullptr) {
        throw std::runtime_error("ICE: ClassType could not be defined in TypeRegistry");
    }

    if (ret->isDefined())
        throw std::invalid_argument("Redefinition of type symbol \"" + className + "\"");
    ret->defineClass();

    classScopes[className] = scopeReg->getNewClassScope(ctx, reg, this);

    return ret;
}

void GlobalScope::declareFunction(const std::string &funName, Type *returnType, std::vector<Type *> argTypes) {
    if (env.envEntryExists(funName)) {
        throw std::invalid_argument("Redefinition of symbol \"" + funName + "\"");
    }
    FunctionType *fType = reg->getFunctionType(returnType, argTypes);
    env.addEnvEntryForId(funName, fType);
}

void GlobalScope::declareFunction(const std::string &funName, Type *returnType) {
    if (env.envEntryExists(funName)) {
        throw std::invalid_argument("Redefinition of symbol \"" + funName + "\"");
    }
    FunctionType *fType = reg->getFunctionType(returnType);
    env.addEnvEntryForId(funName, fType);
}

void GlobalScope::defineFunction(const std::string &funName) {
    if (!env.envEntryExists(funName))
        throw std::invalid_argument("Function \"" + funName + "\" is not declared, so cannot be defined");
    IdEnvEntry &envEntry = env.getEnvEntryForId(funName);
    FunctionType *fType = dynamic_cast<FunctionType *>(envEntry.getEntryType());
    if (fType == nullptr)
        throw std::invalid_argument("Symbol \"" + funName + "\" is not a function");
    envEntry.setEntryFunction(fType->generateFunction(ctx, funName));
}

bool GlobalScope::checkForInheritanceCycles() {
    // Vertex set and adjacency list
    std::unordered_set<ClassType *> classes;
    std::unordered_map<ClassType *, ClassType *> parents;
    std::unordered_map<ClassType *, std::vector<ClassType *>> children;

    // Complete vertex set and adjacency list
    auto typeEntries = reg->getNamedTypes();
    for (auto it : typeEntries) {
        if (it.second->isClass()) {
            ClassType *currentClass = dynamic_cast<ClassType *>(it.second);
            assert(currentClass != nullptr);
            classes.insert(currentClass);
            if (currentClass->getParentClass() != nullptr) {
                if (children.find(currentClass->getParentClass()) == children.end()) {
                    children[currentClass->getParentClass()] = std::vector<ClassType *>{currentClass};
                } else {
                    children[currentClass->getParentClass()].push_back(currentClass);
                }
                parents[currentClass] = currentClass->getParentClass();
            }
        }
    }

    // Algorithm for cycle detection: cycle doesn't exist iff we can delete all
    // vertices of the graph by recursively deleting all vertices with no parents
    while (classes.size() > 0) {
        ClassType *toDelete = nullptr;
        for (ClassType *c : classes) {
            if (parents.find(c) == parents.end()) {
                toDelete = c;
                break;
            }
        }
        // No vertices with no parents
        if (toDelete == nullptr)
            return false;
        for (ClassType *child : children[toDelete])
            parents.erase(child);
        classes.erase(toDelete);
    }

    // All ok
    return true;
}


IdEnvEntry *GlobalScope::getSymbolIdEnvEntry(const std::string &symbol) {
    if (env.envEntryExists(symbol)) {
        IdEnvEntry &entry = env.getEnvEntryForId(symbol);
        return &entry;
    }
    return nullptr;
}

std::vector<std::string> GlobalScope::errorChecks() {
    auto errors = std::vector<std::string>();

    auto undefinedClasses = checkForUndefinedClasses();
    for (std::string &s : undefinedClasses) {
        errors.push_back("Referenced class \"" + s + "\" is undefined");
    }

    bool noCycle = checkForInheritanceCycles();
    if (!noCycle)
        errors.emplace_back("Inheritance cycle detected");

    if (!checkForMain())
        errors.emplace_back("Function int main() not defined");

    return errors;
}

std::vector<std::string> GlobalScope::checkForUndefinedClasses() {
    std::vector<std::string> undefinedClasses;
    auto typeEntries = reg->getNamedTypes();
    for (auto it : typeEntries) {
        if (it.second->isClass() && !it.second->isTypeComplete())
            undefinedClasses.push_back(it.first);
    }
    return undefinedClasses;
}

TypeRegistry *GlobalScope::getTypeRegistry() {
    return reg;
}

ClassScope *GlobalScope::getClassScope(const std::string &classId) {
    if (classScopes.find(classId) != classScopes.end()) {
        return classScopes[classId];
    }
    return nullptr;
}

void GlobalScope::declareClassFunction(const std::string &className, const std::string &funName, Type *returnType,
                                       std::vector<Type *> argTypes) {
    if (!reg->typeExits(className))
        throw std::invalid_argument("\"" + className + "\" is not a class");
    ClassType *classType = dynamic_cast<ClassType *>(reg->getType(className));
    if (classType == nullptr)
        throw std::invalid_argument("\"" + className + "\" is not a class");
    FunctionType *funType = reg->getFunctionType(returnType, argTypes);
    if (classType->getMemberType(funName) != nullptr)
        throw std::invalid_argument("Symbol \"" + funName + "\" already used in class \"" + className + "\"");
    classType->addMember(funName, funType);
}

void GlobalScope::defineClassFunction(const std::string &className, const std::string &funName) {
    if (!reg->typeExits(className))
        throw std::invalid_argument("\"" + className + "\" is not a class");
    ClassType *classType = dynamic_cast<ClassType *>(reg->getType(className));
    if (classType == nullptr)
        throw std::invalid_argument("\"" + className + "\" is not a class");
    FunctionType *funType = dynamic_cast<FunctionType *>(classType->getMemberType(funName));
    if (funType == nullptr)
        throw std::invalid_argument("Function \"" + funName + "\" is not declared in class\"" + className + "\"");
    try {
        env.addEnvEntryForId(className + "." + funName, funType);
    } catch (std::invalid_argument &e) {
        throw e;
    }
    IdEnvEntry &funIdEnvEntry = env.getEnvEntryForId(className + "." + funName);
    funIdEnvEntry.setEntryFunction(funType->generateFunction(ctx, className + "." + funName));
}

void GlobalScope::defineClassVariable(const std::string &className, const std::string &varName, Type *t) {
    if (!reg->typeExits(className))
        throw std::invalid_argument("\"" + className + "\" is not a class");
    ClassType *classType = dynamic_cast<ClassType *>(reg->getType(className));
    if (classType == nullptr)
        throw std::invalid_argument("\"" + className + "\" is not a class");
    if (classType->getMemberType(varName) != nullptr)
        throw std::invalid_argument("Symbol \"" + varName + "\" already used in class \"" + className + "\"");
    classType->addMember(varName, t);
}

bool GlobalScope::checkForMain() {
    if (!env.envEntryExists("main"))
        return false;
    IdEnvEntry &mainEntry = env.getEnvEntryForId("main");
    FunctionType *expectedType = reg->getFunctionType(reg->getIntType());
    Type *actualType = mainEntry.getEntryType();
    return (*expectedType == *actualType);
}
