#pragma once

#include <iostream>
#include <string>
#include <variant>
#include <list>

using PyValue = std::variant<int, double, bool, std::string>;

class PyQueue {
public:
    PyQueue() = default;

    void Enqueue(PyValue val);
    PyValue Dequeue();
    PyValue Peek() const;
    bool isEmpty() const;
    size_t Size() const;

private:
    std::list<PyValue> queue;
};
