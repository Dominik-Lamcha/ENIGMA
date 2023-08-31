#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Rotor.hpp" 

using namespace std;



// Simple reflector
class Reflector {
public:
    Reflector(string mapping) : mapping(mapping) {}

    char reflect(char in) {
        int inPos = in - 'A';
        return mapping[inPos];
    }

private:
    string mapping;
};

// Enigma machine with one rotor and one reflector
class Enigma {
public:
    Enigma(Rotor rotor, Reflector reflector) : rotor(rotor), reflector(reflector) {}

    char encrypt(char in) {
        char r = rotor.map(in);
        char ref = reflector.reflect(r);
        char out = rotor.map(ref);
        rotor.rotate();
        return out;
    }

private:
    Rotor rotor;
    Reflector reflector;
};

int main() {
    // Initialize rotor and reflector
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    rotor.setPosition(0);
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // Initialize Enigma machine
    Enigma enigma(rotor, reflector);

    // Get plaintext
    cout << "Enter plaintext: ";
    string plaintext;
    cin >> plaintext;

    // Encrypt
    string ciphertext;
    for (char c : plaintext) {
        ciphertext += enigma.encrypt(c);
        
    }

    // Output ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
