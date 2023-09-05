#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype> 
#include "Enigma.hpp"

using namespace std;

int main() {
    // Initialize rotor and reflector
    Rotor rotor1(2);
    rotor1.setOffset(0);
    Reflector reflector("EJMZALYXVBWFCRQUONTSPIKHGD");
    Plugboard plugboard("");

    // Initialize Enigma machine
    Enigma enigma(rotor1, reflector, plugboard);

    // Get plaintext
    cout << "Enter plaintext: ";
    string plaintext;
    cin >> plaintext;

    // Encrypt
    string ciphertext;
    for (char c : plaintext) {
        c = toupper(c);
        ciphertext += enigma.encrypt(c);
        
    }

    // Output ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
