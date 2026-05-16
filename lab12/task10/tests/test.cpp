#include <gtest/gtest.h>
#include <memory>
#include "../public/DomainTypes.h"

TEST(WeakPtrTest, WeakPtrDoesNotIncreaseUseCount) {
    auto track = std::make_shared<Track>("Track");
    auto effect = std::make_shared<Effect>("Effect");

    EXPECT_EQ(track.use_count(), 1);

    effect->setTrack(track);

    EXPECT_EQ(track.use_count(), 1);
}

TEST(WeakPtrTest, SharedCycleIncreasesCounts) {
    auto track = std::make_shared<BadTrack>("BadTrack");
    auto effect = std::make_shared<BadEffect>("BadEffect");

    track->setEffect(effect);
    effect->setTrack(track);

    EXPECT_GT(track.use_count(), 1);
    EXPECT_GT(effect.use_count(), 1);
}

TEST(WeakPtrTest, WeakPtrLockProvidesTemporaryAccess) {
    auto track = std::make_shared<Track>("Track");
    auto effect = std::make_shared<Effect>("Effect");

    effect->setTrack(track);

    EXPECT_EQ(track.use_count(), 1);
}

TEST(WeakPtrTest, GoodNodePreviousDoesNotIncreaseCount) {
    auto node1 = std::make_shared<GoodNode>(1);
    auto node2 = std::make_shared<GoodNode>(2);

    node1->next = node2;
    node2->previous = node1;

    EXPECT_EQ(node1.use_count(), 1);
}

TEST(WeakPtrTest, BadNodeCreatesCycle) {
    auto node1 = std::make_shared<BadNode>(1);
    auto node2 = std::make_shared<BadNode>(2);

    node1->next = node2;
    node2->previous = node1;

    EXPECT_GT(node1.use_count(), 1);
}