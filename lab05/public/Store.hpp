#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include <string>
#include "Product.hpp"
#include "SupportAgent.hpp"
#include "Customer.hpp"

class Store {
private:
    std::string name;

    std::vector<Product> products;
    std::vector<SupportAgent> agents;
    std::vector<Customer> customers;

public:
    Store();
    Store(const std::string& name);

    std::string getName() const;

    void addProduct(const Product& product);
    bool removeProduct(int productId);
    Product* findProduct(int productId);
    const std::vector<Product>& getProducts() const;

    void addSupportAgent(const SupportAgent& agent);
    SupportAgent* findSupportAgent(int agentId);
    const std::vector<SupportAgent>& getSupportAgents() const;

    void registerCustomer(const Customer& customer);
    Customer* findCustomer(int customerId);
    const std::vector<Customer>& getCustomers() const;
};

#endif