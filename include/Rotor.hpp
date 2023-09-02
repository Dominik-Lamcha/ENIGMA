#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>

class Rotor {
private:
    std::unordered_map<char, char> forwardMappings;
    std::unordered_map<char, char> reverseMappings;
    int offset;

public:
    Rotor(const std::string& settings);
    void setOffset(int newOffset);
    char forward(char input) const;
    char reverse(char input) const;
    void rotate();
};

#endif // ROTOR_HPP
