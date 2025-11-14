#pragma once

#include <vector>
#include <variant>
#include <string>

using PyValue = std::variant<int, double, bool, std::string>;

class PyList {
private:
    std::vector<PyValue> array;

public:
    void add_var(const PyValue& val);
    void print() const;
};
