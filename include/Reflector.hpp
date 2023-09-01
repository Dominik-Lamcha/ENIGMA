#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>

class Reflector {
private:
    std::unordered_map<char, char> mappings;

public:
    Reflector(const std::string& settings);
    char reflect(char input) const;
};

#endif // REFLECTOR_HPP
