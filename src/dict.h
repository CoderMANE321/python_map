#pragma once

#include <map>
#include <variant>
#include <string>

using PyValue = std::variant<int, double, bool, std::string>;

class PyDict {
public:
    PyDict() = default;

    void Insert(int key, PyValue val);
    PyValue Get(int key) const;
    bool Remove(int key);
    void print() const;

    size_t Size() const;
    bool isEmpty() const;

private:
    std::map<int, PyValue> dict;
};
