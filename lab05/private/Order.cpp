#include "Order.hpp"

Order::Order() : id(0) {}

Order::Order(int id) : id(id) {}

int Order::getId() const {
    return id;
}

void Order::addProduct(const Product& product) {
    products.push_back(product);
}

const std::vector<Product>& Order::getProducts() const {
    return products;
}