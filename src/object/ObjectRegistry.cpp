#include "object/ObjectRegistry.hpp"
#include "object/Object.hpp"
#include <stdexcept>

ObjectRegistry& ObjectRegistry::instance() {
    static ObjectRegistry registry;
    return registry;
}

void ObjectRegistry::registerObject(const std::string& name, Creator creator) {
    creators_[name] = std::move(creator);
}

std::unique_ptr<Object> ObjectRegistry::create(const std::string& name) const {
    auto it = creators_.find(name);
    if (it == creators_.end()) {
        throw std::runtime_error("Unknown object: " + name);
    }
    return it->second();
}
