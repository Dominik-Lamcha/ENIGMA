#include <gtest/gtest.h>
#include <stdexcept>
#include "Rotor.hpp"  // Make sure to include the correct path to your Rotor header file.

TEST(RotorTest, ForwardMapping) {
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");  // Example rotor mapping
    EXPECT_EQ(rotor.forward('A'), 'E');
    EXPECT_EQ(rotor.forward('B'), 'K');
}

TEST(RotorTest, ReverseMapping) {
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");  // Example rotor mapping
    EXPECT_EQ(rotor.reverse('E'), 'A');
    EXPECT_EQ(rotor.reverse('K'), 'B');
}

TEST(RotorTest, OffsetChange) {
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");  // Example rotor mapping
    rotor.setOffset(1);
    EXPECT_EQ(rotor.forward('A'), 'K');
    EXPECT_EQ(rotor.reverse('K'), 'A');
}

TEST(RotorTest, Rotation) {
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");  // Example rotor mapping
    rotor.rotate();  // Offset should now be 1
    EXPECT_EQ(rotor.forward('A'), 'K');
}

TEST(RotorTest, InvalidSettings) {
    EXPECT_THROW(Rotor("EKMFLGDQVZNTOWYHXUSPAIBRC"), std::runtime_error);
    EXPECT_THROW(Rotor(""), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
