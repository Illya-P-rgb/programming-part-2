#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include "../public/DomainTypes.h"

AudioBufferResource* createTestBuffer() {
    auto* res = new AudioBufferResource;
    res->size = 3;
    res->rawData = new int[3]{1, 2, 3};
    return res;
}

TEST(AudioBufferHandleTest, StoresAndAccessesResource) {
    AudioBufferHandle handle(createTestBuffer());

    ASSERT_NE(handle.get(), nullptr);
    EXPECT_EQ(handle.get()->size, 3);

    EXPECT_EQ(handle.get()->rawData[0], 1);
    EXPECT_EQ(handle.get()->rawData[1], 2);
    EXPECT_EQ(handle.get()->rawData[2], 3);
}

TEST(AudioBufferHandleTest, MoveConstructorTransfersOwnership) {
    AudioBufferHandle a(createTestBuffer());

    AudioBufferHandle b(std::move(a));

    EXPECT_NE(b.get(), nullptr);
    EXPECT_EQ(b.get()->size, 3);

    EXPECT_EQ(a.get(), nullptr);
}

TEST(AudioBufferHandleTest, MoveAssignmentTransfersOwnership) {
    AudioBufferHandle a(createTestBuffer());
    AudioBufferHandle b(createTestBuffer());

    b = std::move(a);

    EXPECT_NE(b.get(), nullptr);
    EXPECT_EQ(a.get(), nullptr);
}

TEST(AudioBufferHandleTest, DataIntegrityAfterMove) {
    AudioBufferHandle a(createTestBuffer());
    AudioBufferHandle b(std::move(a));

    auto* res = b.get();

    EXPECT_EQ(res->rawData[0], 1);
    EXPECT_EQ(res->rawData[1], 2);
    EXPECT_EQ(res->rawData[2], 3);
}

TEST(AudioBufferHandleTest, CopyIsDisabledConceptually) {
    static_assert(!std::is_copy_constructible_v<AudioBufferHandle>);
    static_assert(!std::is_copy_assignable_v<AudioBufferHandle>);
}