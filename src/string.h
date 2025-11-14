#pragma once
#include <iostream>
#include <string>
#include <vector>

class PyString {
private:
    std::vector<char> word;

public:
    PyString();                       // default constructor
    PyString(const std::string& s);   // construct from std::string

    void add_character(char c);
    std::string create_word() const;
    void print_word() const;
    size_t length() const;

    bool test_string(const std::string& c_string,
                     const std::string& p_string) const;
};
