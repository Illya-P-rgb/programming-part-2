#include <gtest/gtest.h>
#include <utility>
#include <stdexcept>
#include "../public/SimplePtr.h"
#include "../public/DomainTypes.h"

// Basic ownership
TEST(SimplePtrTest, StoresAndAccessesObject) {
    SimplePtr<Sample> ptr(new Sample(100, 0.5));

    EXPECT_EQ(ptr->getAmplitude(), 100);
    EXPECT_DOUBLE_EQ(ptr->getTimestamp(), 0.5);
}

// Dereference operator
TEST(SimplePtrTest, DereferenceOperatorWorks) {
    SimplePtr<Sample> ptr(new Sample(250, 2.0));

    EXPECT_EQ((*ptr).getAmplitude(), 250);
}

// Move constructor
TEST(SimplePtrTest, MoveConstructorTransfersOwnership) {
    SimplePtr<Sample> original(new Sample(300, 3.0));

    SimplePtr<Sample> moved(std::move(original));

    EXPECT_EQ(moved->getAmplitude(), 300);
    EXPECT_EQ(original.get(), nullptr);
}

// Move assignment
TEST(SimplePtrTest, MoveAssignmentTransfersOwnership) {
    SimplePtr<Sample> source(new Sample(400, 4.0));
    SimplePtr<Sample> target;

    target = std::move(source);

    EXPECT_EQ(target->getAmplitude(), 400);
    EXPECT_EQ(source.get(), nullptr);
}

// Null dereference protection
TEST(SimplePtrTest, ThrowsOnNullDereference) {
    SimplePtr<Sample> ptr;

    EXPECT_THROW(*ptr, std::runtime_error);
    EXPECT_THROW(ptr->getAmplitude(), std::runtime_error);
}