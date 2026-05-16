#include <gtest/gtest.h>
#include <stdexcept>
#include "../public/SampleBuffer.h"

TEST(SampleBufferTest, CorrectSizeInitialization) {
    SampleBuffer buffer(4);
    EXPECT_EQ(buffer.size(), 4);
}

TEST(SampleBufferTest, CopyConstructorCreatesIndependentCopy) {
    SampleBuffer original(2);

    original.fillSample(0, 100, 0.1);
    original.fillSample(1, 200, 0.2);

    SampleBuffer copy(original);

    original.fillSample(0, 999, 9.9);

    EXPECT_EQ(copy[0].getAmplitude(), 100);
    EXPECT_DOUBLE_EQ(copy[0].getTimestamp(), 0.1);

    EXPECT_EQ(copy[1].getAmplitude(), 200);
}

TEST(SampleBufferTest, CopyAssignmentCreatesIndependentCopy) {
    SampleBuffer original(2);
    original.fillSample(0, 50, 0.5);
    original.fillSample(1, 60, 0.6);

    SampleBuffer assigned(1);
    assigned = original;

    // Modify original
    original.fillSample(1, 777, 7.7);

    EXPECT_EQ(assigned[1].getAmplitude(), 60);
    EXPECT_DOUBLE_EQ(assigned[1].getTimestamp(), 0.6);
}

TEST(SampleBufferTest, SelfAssignmentSafe) {
    SampleBuffer buffer(2);

    buffer.fillSample(0, 10, 0.1);
    buffer.fillSample(1, 20, 0.2);

    buffer = buffer;

    EXPECT_EQ(buffer[0].getAmplitude(), 10);
    EXPECT_EQ(buffer[1].getAmplitude(), 20);
}

TEST(SampleBufferTest, ThrowsOnOutOfBoundsAccess) {
    SampleBuffer buffer(2);

    EXPECT_THROW(buffer[2], std::out_of_range);
    EXPECT_THROW(buffer.fillSample(5, 100, 0.1), std::out_of_range);
}