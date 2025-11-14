#pragma once

#include <iostream>
#include <string>
#include <variant>
#include <deque>

using PyValue = std::variant<int, double, bool, std::string>;

class PyStack {
public:
    PyStack() = default;
    PyStack(const PyValue& val);

    void Push(const PyValue& val);
    PyValue Pop();
    PyValue Peek() const;

    size_t Size() const;
    bool isEmpty() const;

    void print() const;

private:
    std::deque<PyValue> stack;
};

