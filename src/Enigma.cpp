#include "Enigma.hpp"

Enigma::Enigma(Rotor rotor, Reflector reflector) : rotor(rotor), reflector(reflector) {}

char Enigma::encrypt(char in) {
    char r = rotor.forward(in);
    char ref = reflector.reflect(r);
    char out = rotor.reverse(ref);
    //rotor.rotate();
    return out;
}
