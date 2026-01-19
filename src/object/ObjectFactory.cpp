#include "object/ObjectFactory.hpp"
#include "object/ObjectRegistry.hpp"
#include "object/Object.hpp"

std::unique_ptr<Object> ObjectFactory::create(const std::string& name) {
    return ObjectRegistry::instance().create(name);
}
