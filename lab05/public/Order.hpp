#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include "Product.hpp"

class Order {
private:
    int id;
    std::vector<Product> products;
    double totalPrice;

public:
    Order();
    Order(int id);

    int getId() const;
    double getTotalPrice() const;

    void addProduct(const Product& product);
    const std::vector<Product>& getProducts() const;

    void calculateTotal();
};

#endif