#include "objects/Square.hpp"
#include "object/ObjectRegistry.hpp"
#include <sstream>

namespace {
bool registered = [] {
    ObjectRegistry::instance().registerObject(
        "square", [] { return std::make_unique<Square>(); });
    return true;
}();
}

std::string Square::name() const {
    return "square";
}

std::string Square::description() const {
    return "A square has four sides of equal length.";
}

void Square::configure(const std::vector<double>& params) {
    if (params.size() != 1) {
        throw std::runtime_error("Square requires 1 parameter: side length");
    }
    sideLength_ = params[0];
}

std::string Square::properties() const {
    double area = sideLength_ * sideLength_;
    double perimeter = 4 * sideLength_;

    std::ostringstream oss;
    oss << "Area: " << area << "\n"
        << "Perimeter: " << perimeter;
    return oss.str();
}
