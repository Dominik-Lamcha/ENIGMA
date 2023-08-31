#include "Reflector.hpp"

Reflector::Reflector(std::string mapping) : mapping(mapping) {}

char Reflector::reflect(char in) {
    int inPos = in - 'A';
    return mapping[inPos];
}