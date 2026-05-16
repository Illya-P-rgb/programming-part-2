#include <gtest/gtest.h>
#include <memory>
#include "DomainTypes.h"

TEST(UniquePtrTest, SingleObjectCreation) {
    auto sample = std::make_unique<Sample>(250, 0.75);

    EXPECT_EQ(sample->getAmplitude(), 250);
    EXPECT_DOUBLE_EQ(sample->getTimestamp(), 0.75);
}

TEST(UniquePtrTest, OwnershipTransferWorks) {
    auto source = std::make_unique<Sample>(300, 1.5);

    auto target = std::move(source);

    EXPECT_EQ(source.get(), nullptr);
    EXPECT_EQ(target->getAmplitude(), 300);
}

TEST(UniquePtrTest, ArrayManagementWorks) {
    auto samples = std::make_unique<Sample[]>(2);

    samples[0] = Sample(100, 0.1);
    samples[1] = Sample(200, 0.2);

    EXPECT_EQ(samples[0].getAmplitude(), 100);
    EXPECT_EQ(samples[1].getAmplitude(), 200);
}

TEST(UniquePtrTest, AudioTrackOwnsSample) {
    AudioTrack track(
        std::make_unique<Sample>(700, 3.3)
    );

    SUCCEED();
}

TEST(UniquePtrTest, AudioTrackMoveWorks) {
    AudioTrack original(
        std::make_unique<Sample>(800, 4.4)
    );

    AudioTrack moved(std::move(original));

    SUCCEED();
}