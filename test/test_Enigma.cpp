#include <gtest/gtest.h>
#include "Enigma.hpp"  // Make sure to include the correct path to your Enigma header file.
#include "Rotor.hpp"   // Include the Rotor header file.
#include "Reflector.hpp"  // Include the Reflector header file.

TEST(EnigmaTest, BasicEncryption) {
    // Initialize rotor and reflector.
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    
    // Create Enigma machine with the rotor and reflector.
    Enigma enigma(rotor, reflector);
    
    // Test basic encryption.
    EXPECT_EQ(enigma.encrypt('A'), 'H');
}

TEST(EnigmaTest, RotationEffect) {
    // Initialize rotor and reflector.
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    
    // Create Enigma machine with the rotor and reflector.
    Enigma enigma(rotor, reflector);
    
    // Encrypt a character, causing the rotor to rotate.
    enigma.encrypt('A');
    
    // Test that the rotation affected the encryption.
    EXPECT_EQ(enigma.encrypt('A'), 'N');
}

// You can add more tests here based on your needs, such as testing for different rotor/rotor combinations, invalid inputs, etc.

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
