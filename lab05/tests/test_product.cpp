#include <gtest/gtest.h>
#include "Product.hpp"

TEST(ProductTest, ConstructorSetsValues) {
    Product p(1, "Laptop", 1200.0);

    EXPECT_EQ(p.getId(), 1);
    EXPECT_DOUBLE_EQ(p.getPrice(), 1200.0);
}

TEST(ProductTest, MultipleProductsDifferentIds) {
    Product p1(1, "Mouse", 25.0);
    Product p2(2, "Keyboard", 80.0);

    EXPECT_NE(p1.getId(), p2.getId());
}