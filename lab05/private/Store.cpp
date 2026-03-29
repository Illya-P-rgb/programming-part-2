#include "Store.hpp"

Store::Store() : name("Unnamed Store") {}

Store::Store(const std::string& name) : name(name) {}

std::string Store::getName() const {
    return name;
}


void Store::addProduct(const Product& product) {
    products.push_back(product);
}

bool Store::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

Product* Store::findProduct(int productId) {
    for (auto& product : products) {
        if (product.getId() == productId) {
            return &product;
        }
    }
    return nullptr;
}

const std::vector<Product>& Store::getProducts() const {
    return products;
}


void Store::addSupportAgent(const SupportAgent& agent) {
    agents.push_back(agent);
}

SupportAgent* Store::findSupportAgent(int agentId) {
    for (auto& agent : agents) {
        if (agent.getId() == agentId) {
            return &agent;
        }
    }
    return nullptr;
}

const std::vector<SupportAgent>& Store::getSupportAgents() const {
    return agents;
}


void Store::registerCustomer(const Customer& customer) {
    customers.push_back(customer);
}

Customer* Store::findCustomer(int customerId) {
    for (auto& customer : customers) {
        if (customer.getId() == customerId) {
            return &customer;
        }
    }
    return nullptr;
}

const std::vector<Customer>& Store::getCustomers() const {
    return customers;
}