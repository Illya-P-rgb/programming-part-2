#include <gtest/gtest.h>
#include <utility>
#include <stdexcept>
#include "../public/SampleBuffer.h"

TEST(SampleBufferTest, CopyConstructorDeepCopy) {
    SampleBuffer original(2);

    original.fillSample(0, 100, 0.1);
    original.fillSample(1, 200, 0.2);

    SampleBuffer copy(original);

    original.fillSample(0, 999, 9.9);

    EXPECT_EQ(copy[0].getAmplitude(), 100);
    EXPECT_DOUBLE_EQ(copy[0].getTimestamp(), 0.1);
}

TEST(SampleBufferTest, MoveConstructorTransfersOwnership) {
    SampleBuffer original(2);

    original.fillSample(0, 100, 0.1);
    original.fillSample(1, 200, 0.2);

    SampleBuffer moved(std::move(original));

    EXPECT_EQ(moved.size(), 2);
    EXPECT_EQ(moved[0].getAmplitude(), 100);

    EXPECT_EQ(original.size(), 0);
}

TEST(SampleBufferTest, MoveAssignmentTransfersOwnership) {
    SampleBuffer source(2);

    source.fillSample(0, 50, 0.5);
    source.fillSample(1, 60, 0.6);

    SampleBuffer target(1);

    target = std::move(source);

    EXPECT_EQ(target.size(), 2);
    EXPECT_EQ(target[1].getAmplitude(), 60);

    EXPECT_EQ(source.size(), 0);
}

TEST(SampleBufferTest, BoundsCheckingStillWorks) {
    SampleBuffer buffer(1);

    EXPECT_THROW(buffer[5], std::out_of_range);
}

TEST(SampleBufferTest, SelfMoveAssignmentSafe) {
    SampleBuffer buffer(1);

    buffer.fillSample(0, 42, 0.42);

    buffer = std::move(buffer);

    EXPECT_TRUE(buffer.size() == 1 || buffer.size() == 0);
}