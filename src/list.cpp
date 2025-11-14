#include "list.h"
#include <iostream>

void PyList::add_var(const PyValue& val) {
    array.push_back(val);
}

void PyList::print() const {
    std::cout << "[";

    for (size_t i = 0; i < array.size(); i++) {
        std::visit([](auto&& arg) {
            std::cout << arg;
        }, array[i]);

        if (i + 1 < array.size())
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}
