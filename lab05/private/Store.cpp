#include "Store.hpp"

void Store::addProduct(const Product& product) {
    products.push_back(product);
}

void Store::addSupportAgent(const SupportAgent& agent) {
    agents.push_back(agent);
}

void Store::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

Product* Store::findProduct(int id) {
    for (int i = 0; i < (int)products.size(); i++) {
        if (products[i].getId() == id) {
            return &products[i];
        }
    }
    return nullptr;
}

Customer* Store::findCustomer(int id) {
    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i].getId() == id) {
            return &customers[i];
        }
    }
    return nullptr;
}