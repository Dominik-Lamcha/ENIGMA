#include "Enigma.hpp"
#include <iostream>

Enigma::Enigma(Rotor rotor, Reflector reflector) : rotor(rotor), reflector(reflector) {}

char Enigma::encrypt(char in) {
    
    std::cout << in <<std::endl;
    char r = rotor.forward(in);
    std::cout << r <<std::endl;
    char ref = reflector.reflect(r);
    std::cout << ref <<std::endl;
    char out = rotor.reverse(ref);
    std::cout << out <<std::endl;
    rotor.rotate();
    return out;
}
