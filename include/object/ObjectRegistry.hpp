#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

class Object;

class ObjectRegistry {
public:
    using Creator = std::function<std::unique_ptr<Object>()>;

    static ObjectRegistry& instance();

    void registerObject(const std::string& name, Creator creator);
    std::unique_ptr<Object> create(const std::string& name) const;

private:
    std::unordered_map<std::string, Creator> creators_;
};
