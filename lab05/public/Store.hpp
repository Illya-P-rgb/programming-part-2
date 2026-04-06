#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include "Product.hpp"
#include "SupportAgent.hpp"
#include "Customer.hpp"

class Store {
private:
    std::vector<Product> products;
    std::vector<SupportAgent> agents;
    std::vector<Customer> customers;

public:
    void addProduct(const Product& product);
    void addSupportAgent(const SupportAgent& agent);
    void addCustomer(const Customer& customer);

    Product* findProduct(int id);
    Customer* findCustomer(int id);
};

#endif