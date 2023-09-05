#include "Plugboard.hpp"
#include <stdexcept>

Plugboard::Plugboard(const std::string& settings) {
    validateSettings(settings);
    for (std::size_t i = 0; i < settings.size(); i += 2) {
        board[settings[i]] = settings[i + 1];
        board[settings[i + 1]] = settings[i];
    }
}

char Plugboard::swap(char in) {
    return board.count(in) ? board[in] : in;
}

void Plugboard::validateSettings(const std::string& settings) {
    if (settings.size() % 2 != 0) {
        throw std::runtime_error("Plugboard settings must contain an even number of characters.");
    }
    for (char ch : settings) {
        if (ch < 'A' || ch > 'Z') {
            throw std::runtime_error("Plugboard settings must contain only uppercase alphabetic characters.");
        }
    }
}
