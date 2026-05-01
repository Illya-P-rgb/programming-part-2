#include <gtest/gtest.h>
#include <string>

#include "FixedDictionary.hpp"

TEST(FixedDictionaryTest, InsertAndFindStringKey) {
    FixedDictionary<std::string, int, 3> dict;

    EXPECT_TRUE(dict.insert("Apple", 10));
    EXPECT_TRUE(dict.containsKey("Apple"));

    const int* value = dict.findValue("Apple");
    ASSERT_NE(value, nullptr);
    EXPECT_EQ(*value, 10);
}

TEST(FixedDictionaryTest, CStringSpecializationWorks) {
    FixedDictionary<const char*, int, 3> dict;

    EXPECT_TRUE(dict.insert("Orange", 15));
    EXPECT_TRUE(dict.insert("Grape", 30));

    EXPECT_TRUE(dict.containsKey("Orange"));
    EXPECT_TRUE(dict.containsKey("Grape"));

    const int* value = dict.findValue("Orange");
    ASSERT_NE(value, nullptr);
    EXPECT_EQ(*value, 15);
}

TEST(FixedDictionaryTest, CapacityLimit) {
    FixedDictionary<int, int, 2> dict;

    EXPECT_TRUE(dict.insert(1, 100));
    EXPECT_TRUE(dict.insert(2, 200));
    EXPECT_FALSE(dict.insert(3, 300));
}