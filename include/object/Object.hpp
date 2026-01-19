#pragma once
#include <string>
#include <vector>

class Object {
public:
    virtual ~Object() = default;

    virtual std::string name() const = 0;
    virtual std::string description() const = 0;

    // Called after parsing CLI args
    virtual void configure(const std::vector<double>& params) = 0;

    // Output computed properties
    virtual std::string properties() const = 0;
};
