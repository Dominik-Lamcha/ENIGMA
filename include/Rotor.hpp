#pragma once

#include <string>

class Rotor {
public:
    Rotor(std::string mapping);
    void setPosition(int pos);
    void rotate();
    char map(char in);

private:
    std::string mapping;
    int position;
};