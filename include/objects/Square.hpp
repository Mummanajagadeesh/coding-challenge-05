#pragma once
#include "object/Object.hpp"

class Square : public Object {
public:
    std::string name() const override;
    std::string description() const override;
    void configure(const std::vector<double>& params) override;
    std::string properties() const override;

private:
    double sideLength_ = 0.0;
};
