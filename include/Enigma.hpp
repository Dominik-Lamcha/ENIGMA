#pragma once

#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"

class Enigma {
public:
    Enigma(Rotor rotor, Reflector reflector, Plugboard plugboard);
    char encrypt(char in);

private:
    Rotor rotor;
    Reflector reflector;
    Plugboard plugboard;
};
