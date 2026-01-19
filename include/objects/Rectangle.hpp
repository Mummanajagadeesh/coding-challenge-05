#pragma once
#include "object/Object.hpp"

class Rectangle : public Object {
public:
    std::string name() const override;
    std::string description() const override;
    void configure(const std::vector<double>& params) override;
    std::string properties() const override;

private:
    double length_ = 0.0;
    double width_ = 0.0;
};
