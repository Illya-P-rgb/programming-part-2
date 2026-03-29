#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>
#include "Order.hpp"

class Customer {
private:
    int id;
    std::string name;
    std::string email;
    std::vector<Order> orders;

public:
    Customer();
    Customer(int id, const std::string& name, const std::string& email);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    void addOrder(const Order& order);
    const std::vector<Order>& getOrders() const;
};

#endif