#include "Order.hpp"

Order::Order() : id(0), totalPrice(0.0) {}

Order::Order(int id) : id(id), totalPrice(0.0) {}

int Order::getId() const {
    return id;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

void Order::addProduct(const Product& product) {
    products.push_back(product);
    calculateTotal();
}

const std::vector<Product>& Order::getProducts() const {
    return products;
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (const auto& p : products) {
        totalPrice += p.getPrice();
    }
}