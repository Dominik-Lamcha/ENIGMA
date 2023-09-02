#include "Rotor.hpp"

Rotor::Rotor(const std::string& settings) : offset(0) {
    if (settings.length() != 26) {
        throw std::runtime_error("Invalid settings length. Should be 26 characters.");
    }

    for (size_t i = 0; i < settings.length(); ++i) {
        char from = 'A' + i;
        char to = settings[i];
        forwardMappings[from] = to;
        reverseMappings[to] = from;
    }
}

void Rotor::setOffset(int newOffset) {
    offset = newOffset % 26;
}

char Rotor::forward(char input) const {
    char rotatedInput = 'A' + (input - 'A' + offset) % 26;
    char mapped = forwardMappings.at(rotatedInput);
    char rotatedOutput = 'A' + (mapped - 'A' - offset + 26) % 26;
    return rotatedOutput;
}

char Rotor::reverse(char input) const {
    char rotatedInput = 'A' + (input - 'A' + offset) % 26;
    char mapped = reverseMappings.at(rotatedInput);
    char rotatedOutput = 'A' + (mapped - 'A' - offset + 26) % 26;
    return rotatedOutput;
}

void Rotor::rotate() {
    setOffset(offset + 1);
}
