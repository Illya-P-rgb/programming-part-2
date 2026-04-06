#include <iostream>
#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"
#include "Order.hpp"

int main() {
    Store store;

    store.addProduct(Product(1, "Laptop", 1200.0));

    store.addCustomer(Customer(100));

    Order order(1);

    Product* product = store.findProduct(1);
    if (product != nullptr) {
        order.addProduct(*product);
    }

    Customer* customer = store.findCustomer(100);
    if (customer != nullptr) {
        customer->addOrder(order);
    }

    std::cout << "Demo completed" << std::endl;

    return 0;
}