#include "object/ObjectFactory.hpp"
#include "object/Object.hpp"

#include <cassert>
#include <vector>
#include <iostream>

int main() {
    {
        auto c = ObjectFactory::create("circle");
        c->configure({5});
        auto out = c->properties();
        assert(out.find("Area") != std::string::npos);
    }

    {
        auto s = ObjectFactory::create("square");
        s->configure({4});
        auto out = s->properties();
        assert(out.find("Perimeter") != std::string::npos);
    }

    {
        auto r = ObjectFactory::create("rect");
        r->configure({4, 6});
        auto out = r->properties();
        assert(out.find("Area") != std::string::npos);
    }

    std::cout << "All tests passed\n";
    return 0;
}
