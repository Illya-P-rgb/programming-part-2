#include <iostream>
#include "lib.hpp"

int main() {
    DeliveryOrder order(101, 12.5, 250.0, false, 3);

    std::cout << "Order number: " << order.getOrderNumber() << '\n';
    std::cout << "Distance (km): " << order.getDistanceKm() << '\n';
    std::cout << "Price: " << order.getPrice() << '\n';
    std::cout << "Delivered: " << (order.getDelivered() ? "yes" : "no") << '\n';
    std::cout << "Priority: " << order.getPriority() << '\n';

    std::cout << "Cost per km: " << order.deliveryCostPerKm() << '\n';
    std::cout << "Is urgent: " << (order.isUrgent() ? "yes" : "no") << '\n';

    std::cout << "Discounted price (10%): " << order.discountedPrice(10) << '\n';

    order.increasePriority();
    std::cout << "Priority after increase: " << order.getPriority() << '\n';

    order.markDelivered();
    std::cout << "Delivered after update: " << (order.getDelivered() ? "yes" : "no") << '\n';

    return 0;
}