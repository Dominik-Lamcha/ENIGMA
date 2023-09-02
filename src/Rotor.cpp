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

Rotor::Rotor(const std::string& settings, char first_notch) : offset(0) {
    if (settings.length() != 26) {
        throw std::runtime_error("Invalid settings length. Should be 26 characters.");
    }

    for (size_t i = 0; i < settings.length(); ++i) {
        char from = 'A' + i;
        char to = settings[i];
        forwardMappings[from] = to;
        reverseMappings[to] = from;
    }
    this->first_notch = first_notch;
    this->second_notch = first_notch;
}

Rotor::Rotor(const std::string& settings, char first_notch, char second_notch) : offset(0) {
    if (settings.length() != 26) {
        throw std::runtime_error("Invalid settings length. Should be 26 characters.");
    }

    for (size_t i = 0; i < settings.length(); ++i) {
        char from = 'A' + i;
        char to = settings[i];
        forwardMappings[from] = to;
        reverseMappings[to] = from;
    }
    this->first_notch = first_notch;
    this->second_notch = second_notch;
}

Rotor::Rotor(int rotorNumber) {
    setByNumber(rotorNumber);
}

void Rotor::setByNumber(int rotorNumber) {
    static const std::vector<std::string> rotorConfigs = {
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",  // I
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",  // II
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",  // III
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",  // IV
        "VZBRGITYUPSDNHLXAWMJQOFECK",  // V
        "JPGVOUMFYQBENHZRDKASXLICTW",  // VI
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",  // VII
        "FKQHTLXOCBJSPDZRAMEWNIUYGV"   // VIII
    };
    static const std::vector<char> notchConfigs = {
        'Y',  //I
        'M',  //II
        'D',  //III
        'R',  //IV
        'H'   //V
        
    };

    if (rotorNumber < 1 || rotorNumber > 8) {
        throw std::invalid_argument("Invalid rotor number. Must be between 1 and 5.");
    }

    // Initialize rotor settings based on rotor number

    char first_notch;
    char second_notch;

    if (rotorNumber < 1 || rotorNumber > 5)
    {
        first_notch = notchConfigs[rotorNumber-1];
        second_notch = first_notch;
    }
    else
    {
        first_notch = 'H';
        second_notch = 'U';
    }
    *this = Rotor(rotorConfigs[rotorNumber - 1],first_notch,second_notch);
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
    setOffset(offset+1);

}
