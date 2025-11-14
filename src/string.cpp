#include "string.h"

PyString::PyString() = default;

PyString::PyString(const std::string& s) {
    for (char c : s) {
        word.push_back(c);
    }
}

void PyString::add_character(char c) {
    word.push_back(c);
}

std::string PyString::create_word() const {
    return std::string(word.begin(), word.end());
}

void PyString::print_word() const {
    for (char c : word) {
        std::cout << c;
    }
    std::cout << std::endl;
}

size_t PyString::length() const {
    return word.size();
}

bool PyString::test_string(const std::string& c_string,
                           const std::string& p_string) const {
    return c_string == p_string;
}
