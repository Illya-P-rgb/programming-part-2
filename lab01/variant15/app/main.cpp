#include <iostream>
#include "shopping_list.hpp"
#include <fmt/core.h>

int main() {
    ShoppingList list;
    list.add("Milk");
    list.add("Bread");

    fmt::print("Number of items: {}\n", list.count());
}