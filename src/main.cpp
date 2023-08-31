#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Enigma.hpp"

using namespace std;

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
