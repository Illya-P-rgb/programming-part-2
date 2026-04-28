#include "lib.hpp"

DeliveryOrder::DeliveryOrder(int orderNumber, double distanceKm, double price, bool delivered, int priority)
    : orderNumber(orderNumber),
      distanceKm(distanceKm),
      price(price),
      delivered(delivered),
      priority(priority) {}

int DeliveryOrder::getOrderNumber() const {
    return orderNumber;
}

double DeliveryOrder::getDistanceKm() const {
    return distanceKm;
}

double DeliveryOrder::getPrice() const {
    return price;
}

bool DeliveryOrder::getDelivered() const {
    return delivered;
}

int DeliveryOrder::getPriority() const {
    return priority;
}

void DeliveryOrder::setOrderNumber(int value) {
    orderNumber = value;
}

void DeliveryOrder::setDistanceKm(double value) {
    distanceKm = value;
}

void DeliveryOrder::setPrice(double value) {
    price = value;
}

void DeliveryOrder::setDelivered(bool value) {
    delivered = value;
}

void DeliveryOrder::setPriority(int value) {
    priority = value;
}

void DeliveryOrder::markDelivered() {
    delivered = true;
}

double DeliveryOrder::deliveryCostPerKm() const {
    if (distanceKm == 0)
        return 0;
    return price / distanceKm;
}

bool DeliveryOrder::isUrgent() const {
    return priority >= 5;
}

void DeliveryOrder::increasePriority() {
    priority++;
}

double DeliveryOrder::discountedPrice(double percent) const {
    return price * (1.0 - percent / 100.0);
}