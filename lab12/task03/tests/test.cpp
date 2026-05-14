#include <gtest/gtest.h>
#include <stdexcept>
#include "../public/SampleBuffer.h"

TEST(SampleBufferTest, CorrectSizeInitialization) {
    SampleBuffer buffer(4);

    EXPECT_EQ(buffer.size(), 4);
}

TEST(SampleBufferTest, FillAndRetrieveSamples) {
    SampleBuffer buffer(3);

    buffer.fillSample(0, 100, 0.1);
    buffer.fillSample(1, 200, 0.2);
    buffer.fillSample(2, 300, 0.3);

    EXPECT_EQ(buffer[0].getAmplitude(), 100);
    EXPECT_EQ(buffer[1].getAmplitude(), 200);
    EXPECT_EQ(buffer[2].getAmplitude(), 300);

    EXPECT_DOUBLE_EQ(buffer[0].getTimestamp(), 0.1);
    EXPECT_DOUBLE_EQ(buffer[1].getTimestamp(), 0.2);
    EXPECT_DOUBLE_EQ(buffer[2].getTimestamp(), 0.3);
}

TEST(SampleBufferTest, ThrowsOnOutOfBoundsAccess) {
    SampleBuffer buffer(2);

    EXPECT_THROW(buffer[2], std::out_of_range);
    EXPECT_THROW(buffer.fillSample(3, 100, 0.1), std::out_of_range);
}

TEST(SampleBufferTest, DefaultConstructedSamplesAreZeroed) {
    SampleBuffer buffer(2);

    EXPECT_EQ(buffer[0].getAmplitude(), 0);
    EXPECT_DOUBLE_EQ(buffer[0].getTimestamp(), 0.0);

    EXPECT_EQ(buffer[1].getAmplitude(), 0);
    EXPECT_DOUBLE_EQ(buffer[1].getTimestamp(), 0.0);
}

TEST(SampleBufferTest, HandlesNegativeAmplitude) {
    SampleBuffer buffer(1);

    buffer.fillSample(0, -500, 1.5);

    EXPECT_EQ(buffer[0].getAmplitude(), -500);
    EXPECT_DOUBLE_EQ(buffer[0].getTimestamp(), 1.5);
}