# Lab 04 — Simple Classes and Unit Testing


---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov  
**Date:** 25.03.2026

---



## Structure

```text
lab04/
├── assets/
    └── main.cpp
├──include/
    └── lib.hpp
├──src/
    └── lib.spp
├──uml/
    ├── Diagram.puml
    └── Diagram.png
├── tests
    ├── tests.cpp
    └── test_main.cpp
├──CMakeLists.txt
├──Report.md
```


## The specification of the selected variant

```
Variant 15. DeliveryOrder
Class description. The class describes one delivery order.
Fields:
• int orderNumber
• double distanceKm
• double price
• bool delivered
• int priority
Main interface to implement:
• DeliveryOrder(int orderNumber, double distanceKm, double
price, bool delivered, int priority)
• void markDelivered()
• double deliveryCostPerKm() const
• bool isUrgent() const
• void increasePriority()
• double discountedPrice(double percent) const
Required getters and setters:
• int getOrderNumber() const, void setOrderNumber(int value)
• double getDistanceKm() const, void setDistanceKm(double
value)
• double getPrice() const, void setPrice(double value)
• bool getDelivered() const, void setDelivered(bool value)
• int getPriority() const, void setPriority(int value)
```

## CMakeBuild.txt

```
cmake_minimum_required(VERSION 3.20)
project(lab_delivery_order LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(delivery_lib src/lib.cpp)
target_include_directories(delivery_lib PUBLIC include)
target_compile_features(delivery_lib PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(delivery_lib PRIVATE /W4)
else()
    target_compile_options(delivery_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(delivery_app assets/main.cpp)
target_link_libraries(delivery_app PRIVATE delivery_lib)

add_executable(delivery_tests
    tests/test_main.cpp
    tests/tests.cpp
)

target_link_libraries(delivery_tests
    PRIVATE delivery_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(delivery_tests)
```

## test code

```
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
```


## SCreenshots

![alt text](/home/ilya/programming-part-2/lab04/assets/image-1.png)
![alt text](/home/ilya/programming-part-2/lab04/assets/image.png)


## Short Analysis

```
The constructor test verifies that an object is created correctly, and that all fields are initialized with the values passed to the constructor. This is important because incorrect initialization could lead to errors.

Tests for getters and setters check whether the class correctly returns stored values and allows them to be updated. These tests confirm that encapsulation works properly.

Another tested scenario is the calculation of delivery cost per kilometer. The test ensures that the method deliveryCostPerKm() correctly divides the total price by the delivery distance and returns the expected value.

The urgent order check scenario tests the method isUrgent(). This test confirms that the program correctly determines whether an order is considered urgent based on its priority level.

THOSE ARE NOT ALL TESTS, HOWEVER. BUT SINCE THE LAB INSTRUCTION MENTIONED "SHORT", I WON'T BE INCLUDING ALL OF THEM.
```