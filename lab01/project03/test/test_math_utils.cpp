#include <gtest/gtest.h>
#include "math_utils.hpp"

TEST(MathUtilsTest, AddWorks) {
EXPECT_EQ(add(2, 3), 5);
}

TEST(MathUtilsTest, SubWorks) {
EXPECT_EQ(sub(7, 4), 3);
}