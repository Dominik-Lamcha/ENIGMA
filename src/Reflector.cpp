#include "Reflector.hpp"

Reflector::Reflector(const std::string& settings) {
    if (settings.length() != 26) {
        throw std::invalid_argument("Invalid input lenght");
    }

    for (size_t i = 0; i < settings.length(); ++i) {
        char from = 'A' + i;
        char to = settings[i];
        mappings[from] = to;
        mappings[to] = from;
    }
}

Reflector::Reflector(int reflectorNumber) {
    setByNumber(reflectorNumber);
}

void Reflector::setByNumber(int reflectorNumber) {
    static const std::vector<std::string> reflectorConfigs = {
        "EJMZALYXVBWFCRQUONTSPIKHGD",  // I
        "YRUHQSLDPXNGOKMIEBFZCWVJAT",  // II
        "FVPJIAOYEDRZXWGCTKUQSBNMHL",  // III
    };

    if (reflectorNumber < 1 || reflectorNumber > 3) {
        throw std::invalid_argument("Invalid reflector number. Must be between 1 and 3.");
    }

    // Initialize reflector settings based on rotor number
    *this = Reflector(reflectorConfigs[reflectorNumber - 1]);
}

char Reflector::reflect(char input) const {
    auto it = mappings.find(input);
    if (it != mappings.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid input character");
    }
}
