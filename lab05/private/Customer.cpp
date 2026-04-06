#include "Customer.hpp"

Customer::Customer() : id(0) {}

Customer::Customer(int id) : id(id) {}

int Customer::getId() const {
    return id;
}

void Customer::addOrder(const Order& order) {
    orders.push_back(order);
}

const std::vector<Order>& Customer::getOrders() const {
    return orders;
}