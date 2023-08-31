#include "Rotor.hpp"


#include <string>

Rotor::Rotor(std::string mapping) : mapping(mapping), position(0) {}

void Rotor::setPosition(int pos) {
    position = pos;
}

void Rotor::rotate() {
    position = (position + 1) % 26;
}

char Rotor::map(char in) {
    int inPos = in - 'A';
    inPos = (inPos + position) % 26;
    char out = mapping[inPos];
    int outPos = out - 'A';
    outPos = (outPos - position + 26) % 26;
    return 'A' + outPos;
}
