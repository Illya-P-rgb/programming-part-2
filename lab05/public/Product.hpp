#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int stock;

public:
    Product();
    Product(int id, const std::string& name, double price, int stock);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;

    void setPrice(double newPrice);
    void updateStock(int amount);
};

#endif