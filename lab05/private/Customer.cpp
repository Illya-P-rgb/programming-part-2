#include "Customer.hpp"

Customer::Customer() : id(0), name(""), email("") {}

Customer::Customer(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getEmail() const {
    return email;
}

void Customer::addOrder(const Order& order) {
    orders.push_back(order);
}

const std::vector<Order>& Customer::getOrders() const {
    return orders;
}