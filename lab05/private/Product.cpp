#include "Product.hpp"

Product::Product() : id(0), name(""), price(0.0), stock(0) {}

Product::Product(int id, const std::string& name, double price, int stock)
    : id(id), name(name), price(price), stock(stock) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::updateStock(int amount) {
    stock += amount;
}