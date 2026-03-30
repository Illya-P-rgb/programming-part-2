#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>
#include "Order.hpp"

class Customer {
private:
    int id;
    std::vector<Order> orders;

public:
    Customer();
    Customer(int id);

    int getId() const;

    void addOrder(const Order& order);
    const std::vector<Order>& getOrders() const;
};

#endif