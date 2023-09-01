#include <gtest/gtest.h>
#include "Reflector.hpp"
#include <stdexcept>

TEST(ReflectorTest, CheckReflection) {
    Reflector reflector("EJMZALYXVBWFCRQUONTSPIKHGD");

    EXPECT_EQ(reflector.reflect('A'), 'E');
    EXPECT_EQ(reflector.reflect('E'), 'A');
    EXPECT_EQ(reflector.reflect('M'), 'C');
    EXPECT_EQ(reflector.reflect('C'), 'M');
}

TEST(ReflectorTest, InvalidInput) {
    Reflector reflector("EJMZALYXVBWFCRQUONTSPIKHGD");

    EXPECT_THROW(reflector.reflect('1'), std::invalid_argument);
    EXPECT_THROW(reflector.reflect('@'), std::invalid_argument);
    EXPECT_THROW(reflector.reflect(' '), std::invalid_argument);
}

TEST(ReflectorTest, InvalidSettings) {
    EXPECT_THROW(Reflector("EJMZALYXVBWFCRQUONTSPIKHGDG"), std::invalid_argument);
    EXPECT_THROW(Reflector("EJMZALYXVBWFCRQUONTSPIKH"), std::invalid_argument);
    EXPECT_THROW(Reflector(""), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
