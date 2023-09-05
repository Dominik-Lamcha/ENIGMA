#include "Enigma.hpp"
#include <iostream>

Enigma::Enigma(Rotor rotor, Reflector reflector, Plugboard plugboard) : rotor(rotor), reflector(reflector), plugboard(plugboard) {}

char Enigma::encrypt(char in) {
    
    char pl = plugboard.swap(in);
    char r = rotor.forward(pl);
    char ref = reflector.reflect(r);
    char lp = rotor.reverse(ref);
    char out = plugboard.swap(lp);
    rotor.rotate();
    return out;
}
