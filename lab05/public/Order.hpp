#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include "Product.hpp"

class Order {
private:
    int id;
    std::vector<Product> products;

public:
    Order();
    Order(int id);

    int getId() const;

    void addProduct(const Product& product);
    const std::vector<Product>& getProducts() const;
};

#endif