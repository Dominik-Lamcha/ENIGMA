#pragma once

#include <string>

class Reflector {
public:
    Reflector(std::string mapping);
    char reflect(char in);


private:
    std::string mapping;
};
