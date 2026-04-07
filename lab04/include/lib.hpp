#pragma once

class DeliveryOrder {
public:
    DeliveryOrder(int orderNumber, double distanceKm, double price, bool delivered, int priority);
    int getOrderNumber() const; 
    void setOrderNumber(int value);
    double getDistanceKm() const;
    void setDistanceKm(double value);
    double getPrice() const; 
    void setPrice(double value);
    bool getDelivered() const;
    void setDelivered(bool value);
    int getPriority() const; 
    void setPriority(int value);

    void markDelivered();
    double deliveryCostPerKm() const;
    bool isUrgent() const;
    void increasePriority();
    double discountedPrice(double percent) const;


private:
    int orderNumber;
    double distanceKm;
    double price;
    bool delivered;
    int priority;
};