#include <gtest/gtest.h>
#include "lib.hpp"

TEST(DeliveryOrderTest, ConstructorInitializesFields) {
    DeliveryOrder order(101, 10.0, 200.0, false, 3);

    EXPECT_EQ(order.getOrderNumber(), 101);
    EXPECT_DOUBLE_EQ(order.getDistanceKm(), 10.0);
    EXPECT_DOUBLE_EQ(order.getPrice(), 200.0);
    EXPECT_FALSE(order.getDelivered());
    EXPECT_EQ(order.getPriority(), 3);
}

TEST(DeliveryOrderTest, GettersAndSettersWork) {
    DeliveryOrder order(1, 5.0, 100.0, false, 2);

    order.setOrderNumber(55);
    order.setDistanceKm(15.5);
    order.setPrice(300.0);
    order.setDelivered(true);
    order.setPriority(7);

    EXPECT_EQ(order.getOrderNumber(), 55);
    EXPECT_DOUBLE_EQ(order.getDistanceKm(), 15.5);
    EXPECT_DOUBLE_EQ(order.getPrice(), 300.0);
    EXPECT_TRUE(order.getDelivered());
    EXPECT_EQ(order.getPriority(), 7);
}

TEST(DeliveryOrderTest, CalculatesCostPerKm) {
    DeliveryOrder order(1, 20.0, 200.0, false, 1);

    double result = order.deliveryCostPerKm();

    EXPECT_DOUBLE_EQ(result, 10.0);
}

TEST(DeliveryOrderTest, DetectsUrgentOrder) {
    DeliveryOrder order(1, 5.0, 100.0, false, 6);

    EXPECT_TRUE(order.isUrgent());
}

TEST(DeliveryOrderTest, PriorityIncreases) {
    DeliveryOrder order(1, 5.0, 100.0, false, 3);

    order.increasePriority();

    EXPECT_EQ(order.getPriority(), 4);
}

TEST(DeliveryOrderTest, DiscountCalculationWorks) {
    DeliveryOrder order(1, 10.0, 200.0, false, 2);

    double discounted = order.discountedPrice(10);

    EXPECT_DOUBLE_EQ(discounted, 180.0);
}

TEST(DeliveryOrderTest, MarksOrderAsDelivered) {
    DeliveryOrder order(1, 5.0, 100.0, false, 2);

    order.markDelivered();

    EXPECT_TRUE(order.getDelivered());
}