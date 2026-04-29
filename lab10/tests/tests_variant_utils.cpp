#include <gtest/gtest.h>
#include "variant_utils.hpp"

using namespace GeometryUtils;

TEST(GeometryUtilsTest, SquareInt) {
    EXPECT_EQ(square(5), 25);
    EXPECT_EQ(square(-4), 16);
}

TEST(GeometryUtilsTest, SquareDouble) {
    EXPECT_DOUBLE_EQ(square(2.5), 6.25);
}

TEST(GeometryUtilsTest, MidpointInt) {
    EXPECT_EQ(midpoint(2, 6), 4);
}

TEST(GeometryUtilsTest, MidpointMixed) {
    EXPECT_DOUBLE_EQ(midpoint(2, 5.0), 3.5);
}

TEST(GeometryUtilsTest, MidpointNegative) {
    EXPECT_DOUBLE_EQ(midpoint(-4, 4), 0.0);
}

TEST(GeometryUtilsTest, DistanceInt) {
    EXPECT_EQ(distance1D(3, 7), 4);
}

TEST(GeometryUtilsTest, DistanceNegative) {
    EXPECT_EQ(distance1D(-5, 3), 8);
}

TEST(GeometryUtilsTest, DistanceCoincident) {
    EXPECT_EQ(distance1D(4, 4), 0);
}

TEST(GeometryUtilsTest, DistanceMixed) {
    EXPECT_DOUBLE_EQ(distance1D(2, 5.5), 3.5);
}