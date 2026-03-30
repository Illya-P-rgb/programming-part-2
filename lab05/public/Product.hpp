#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;

public:
    Product();
    Product(int id, const std::string& name, double price);

    int getId() const;
    double getPrice() const;
};

#endif