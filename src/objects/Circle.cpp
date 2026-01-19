#include "objects/Circle.hpp"
#include "object/ObjectRegistry.hpp"

#include <cmath>
#include <sstream>

namespace {
constexpr double PI = 3.14159265358979323846;

bool registered = [] {
    ObjectRegistry::instance().registerObject(
        "circle", [] { return std::make_unique<Circle>(); });
    return true;
}();
}

std::string Circle::name() const {
    return "circle";
}

std::string Circle::description() const {
    return "A circle has a radius.";
}

void Circle::configure(const std::vector<double>& params) {
    if (params.size() != 1) {
        throw std::runtime_error("Circle requires 1 parameter: radius");
    }
    radius_ = params[0];
}

std::string Circle::properties() const {
    double area = PI * radius_ * radius_;
    double circumference = 2 * PI * radius_;

    std::ostringstream oss;
    oss << "Area: " << area << "\n"
        << "Circumference: " << circumference;
    return oss.str();
}
