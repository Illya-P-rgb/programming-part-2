#include <gtest/gtest.h>
#include "Order.hpp"
#include "Product.hpp"

TEST(OrderTest, AddProductToOrder) {
    Order order(1);
    Product product(1, "Laptop", 1200.0);

    order.addProduct(product);

    EXPECT_EQ(order.getProducts().size(), 1);
}

TEST(OrderTest, OrderStoresMultipleProducts) {
    Order order(1);

    Product p1(1, "Laptop", 1200.0);
    Product p2(2, "Mouse", 25.0);

    order.addProduct(p1);
    order.addProduct(p2);

    EXPECT_EQ(order.getProducts().size(), 2);
}