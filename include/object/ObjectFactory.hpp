#pragma once
#include <memory>
#include <string>

class Object;

class ObjectFactory {
public:
    static std::unique_ptr<Object> create(const std::string& name);
};
