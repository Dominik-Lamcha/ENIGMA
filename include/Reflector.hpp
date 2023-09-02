#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <vector>

class Reflector {
private:
    std::unordered_map<char, char> mappings;
    void setByNumber(int reflectorNumber);

public:
    Reflector(const std::string& settings);
    Reflector(int rotorNumber); 
    char reflect(char input) const;
};

#endif // REFLECTOR_HPP
