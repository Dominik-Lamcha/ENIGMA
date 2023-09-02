#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <vector>

class Rotor {
private:
    std::unordered_map<char, char> forwardMappings;
    std::unordered_map<char, char> reverseMappings;
    int offset;
    void setByNumber(int rotorNumber);

public:
    Rotor(const std::string& settings);
    Rotor(int rotorNumber); 
    void setOffset(int newOffset);
    char forward(char input) const;
    char reverse(char input) const;
    void rotate();
};

#endif // ROTOR_HPP
