#include <gtest/gtest.h>
#include "Plugboard.hpp"

TEST(PlugboardTest, CheckSwap) {
    Plugboard plugboard("AZGT");
    EXPECT_EQ(plugboard.swap('A'), 'Z');
    EXPECT_EQ(plugboard.swap('Z'), 'A');
    EXPECT_EQ(plugboard.swap('G'), 'T');
    EXPECT_EQ(plugboard.swap('T'), 'G');
}

TEST(PlugboardTest, InvalidInput) {
    EXPECT_THROW(Plugboard plugboard("AZG"), std::runtime_error);
    EXPECT_THROW(Plugboard plugboard("A1G"), std::runtime_error);
}

TEST(PlugboardTest, NoSwap) {
    Plugboard plugboard("AZGT");
    EXPECT_EQ(plugboard.swap('B'), 'B');
}

