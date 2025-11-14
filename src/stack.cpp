#include "stack.h"

PyStack::PyStack(const PyValue& val) {
    Push(val);
}

void PyStack::Push(const PyValue& val) {
    stack.push_front(val);
}

PyValue PyStack::Pop() {
    if (stack.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    PyValue val = stack.front();
    stack.pop_front();
    return val;
}

PyValue PyStack::Peek() const {
    if (stack.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stack.front();
}

size_t PyStack::Size() const {
    return stack.size();
}

bool PyStack::isEmpty() const {
    return stack.empty();
}

void PyStack::print() const {
    for (const auto& item : stack) {
        std::visit([](auto&& arg) { std::cout << arg << std::endl; }, item);
    }
}


