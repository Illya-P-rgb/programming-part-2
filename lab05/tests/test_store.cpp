#include <gtest/gtest.h>
#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"

TEST(StoreTest, AddProductToStore) {
    Store store;
    Product product(1, "Laptop", 1200.0);

    store.addProduct(product);

    Product* found = store.findProduct(1);

    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getId(), 1);
}

TEST(StoreTest, AddCustomerToStore) {
    Store store;
    Customer customer(10);

    store.addCustomer(customer);

    Customer* found = store.findCustomer(10);

    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getId(), 10);
}

TEST(StoreTest, FindProductReturnsNullIfMissing) {
    Store store;

    Product* found = store.findProduct(999);

    EXPECT_EQ(found, nullptr);
}