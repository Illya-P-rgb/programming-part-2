#include <gtest/gtest.h>
#include "../public/DomainTypes.h"

TEST(SampleTest, DefaultConstructorInitializesToZero) {
    Sample sample;

    EXPECT_EQ(sample.getAmplitude(), 0);
    EXPECT_DOUBLE_EQ(sample.getTimestamp(), 0.0);
}

TEST(SampleTest, ParameterizedConstructorStoresValues) {
    Sample sample(500, 1.75);

    EXPECT_EQ(sample.getAmplitude(), 500);
    EXPECT_DOUBLE_EQ(sample.getTimestamp(), 1.75);
}

TEST(SampleTest, DynamicArrayStoresMultipleSamplesCorrectly) {
    const int count = 3;

    Sample* samples = new Sample[count];

    samples[0] = Sample(100, 0.1);
    samples[1] = Sample(200, 0.2);
    samples[2] = Sample(300, 0.3);

    EXPECT_EQ(samples[0].getAmplitude(), 100);
    EXPECT_EQ(samples[1].getAmplitude(), 200);
    EXPECT_EQ(samples[2].getAmplitude(), 300);

    EXPECT_DOUBLE_EQ(samples[0].getTimestamp(), 0.1);
    EXPECT_DOUBLE_EQ(samples[1].getTimestamp(), 0.2);
    EXPECT_DOUBLE_EQ(samples[2].getTimestamp(), 0.3);

    delete[] samples;
}

TEST(SampleTest, SupportsNegativeAmplitudeValues) {
    Sample sample(-250, 2.5);

    EXPECT_EQ(sample.getAmplitude(), -250);
    EXPECT_DOUBLE_EQ(sample.getTimestamp(), 2.5);
}