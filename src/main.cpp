#include "object/Object.hpp"
#include "object/ObjectFactory.hpp"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: describe_object <object> [parameters]\n";
        return 1;
    }

    try {
        std::string objectName = argv[1];
        std::vector<double> params;

        for (int i = 2; i < argc; ++i) {
            params.push_back(std::stod(argv[i]));
        }

        auto object = ObjectFactory::create(objectName);

        std::cout << object->description() << "\n";

        if (!params.empty()) {
            object->configure(params);
            std::cout << object->properties() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
