#include "dict.h"
#include <iostream>
#include <stdexcept>

void PyDict::Insert(int key, PyValue val) {
    dict[key] = val;
}

PyValue PyDict::Get(int key) const {
    if (!dict.contains(key)) {
        throw std::runtime_error("Key not found");
    }
    return dict.at(key);
}

bool PyDict::Remove(int key) {
    if (dict.empty()) {
        throw std::runtime_error("Dict is empty");
    }
    return dict.erase(key) > 0;
}

void PyDict::print() const {
    for (const auto& [key, value] : dict) {
        std::cout << key << ": ";
        std::visit([](const auto& arg) {
            std::cout << arg;
        }, value);
        std::cout << "\n";
    }
}

size_t PyDict::Size() const {
    return dict.size();
}

bool PyDict::isEmpty() const {
    return dict.empty();
}