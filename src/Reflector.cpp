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

char Reflector::reflect(char input) const {
    auto it = mappings.find(input);
    if (it != mappings.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid input character");
    }
}
