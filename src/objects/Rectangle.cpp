#include "objects/Rectangle.hpp"
#include "object/ObjectRegistry.hpp"
#include <sstream>

namespace {
bool registered = [] {
    ObjectRegistry::instance().registerObject(
        "rect", [] { return std::make_unique<Rectangle>(); });
    return true;
}();
}

std::string Rectangle::name() const {
    return "rect";
}

std::string Rectangle::description() const {
    return "A rectangle has two pairs of equal-length parallel sides.";
}

void Rectangle::configure(const std::vector<double>& params) {
    if (params.size() != 2) {
        throw std::runtime_error(
            "Rectangle requires 2 parameters: length and width");
    }
    length_ = params[0];
    width_ = params[1];
}

std::string Rectangle::properties() const {
    double area = length_ * width_;
    double perimeter = 2 * (length_ + width_);

    std::ostringstream oss;
    oss << "Area: " << area << "\n"
        << "Perimeter: " << perimeter;
    return oss.str();
}
