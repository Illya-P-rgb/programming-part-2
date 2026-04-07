#include <gtest/gtest.h>
#include "shopping_list.hpp"

TEST(ShoppingListTest, AddRemoveCount) {
    ShoppingList list;
    list.add("Milk");
    list.add("Bread");
    EXPECT_EQ(list.count(), 2);

    list.remove("Milk");
    EXPECT_EQ(list.count(), 1);
}