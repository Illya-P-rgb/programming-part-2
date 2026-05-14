#include <gtest/gtest.h>
#include <memory>
#include "../public/DomainTypes.h"

TEST(SharedPtrTest, SharedOwnershipCountsCorrectly) {
    auto effect = std::make_shared<Effect>("Echo");

    EXPECT_EQ(effect.use_count(), 1);

    Track t1("Track1", effect);
    EXPECT_EQ(effect.use_count(), 2);

    Track t2("Track2", effect);
    EXPECT_EQ(effect.use_count(), 3);
}

TEST(SharedPtrTest, SharedResourceAccessibleAcrossOwners) {
    auto effect = std::make_shared<Effect>("Distortion");

    Track t1("Bass", effect);
    Track t2("Lead", effect);

    EXPECT_EQ(t1.getEffect()->getName(), "Distortion");
    EXPECT_EQ(t2.getEffect()->getName(), "Distortion");
}

TEST(SharedPtrTest, TemporaryOwnersIncreaseAndDecreaseCount) {
    auto effect = std::make_shared<Effect>("Compression");

    EXPECT_EQ(effect.use_count(), 1);

    {
        Track temp("Temp", effect);
        EXPECT_EQ(effect.use_count(), 2);
    }

    EXPECT_EQ(effect.use_count(), 1);
}

TEST(SharedPtrTest, DirectSharedPtrCopiesWork) {
    auto original = std::make_shared<Effect>("Limiter");

    std::shared_ptr<Effect> copy = original;

    EXPECT_EQ(original.use_count(), 2);
    EXPECT_EQ(copy->getName(), "Limiter");
}

TEST(SharedPtrTest, SharedPtrCanBeReset) {
    auto effect = std::make_shared<Effect>("Flanger");

    EXPECT_EQ(effect.use_count(), 1);

    effect.reset();

    EXPECT_EQ(effect.get(), nullptr);
}