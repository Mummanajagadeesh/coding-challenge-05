#pragma once
#include "object/Object.hpp"

class Circle : public Object {
public:
    std::string name() const override;
    std::string description() const override;
    void configure(const std::vector<double>& params) override;
    std::string properties() const override;

private:
    double radius_ = 0.0;
};
