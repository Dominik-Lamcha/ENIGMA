#pragma once

#include "Rotor.hpp"
#include "Reflector.hpp"

class Enigma {
public:
    Enigma(Rotor rotor, Reflector reflector);
    char encrypt(char in);

private:
    Rotor rotor;
    Reflector reflector;
};
