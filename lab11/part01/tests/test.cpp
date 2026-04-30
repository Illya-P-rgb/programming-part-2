#include <gtest/gtest.h>
#include <string>

#include "FixedDictionary.hpp"


TEST(FixedDictionaryTest, InsertAndFind) {
    FixedDictionary<std::string, int, 5> dict;

    EXPECT_TRUE(dict.insert("Apple", 10));
    EXPECT_TRUE(dict.insert("Banana", 20));

    EXPECT_TRUE(dict.containsKey("Apple"));
    EXPECT_TRUE(dict.containsKey("Banana"));
    EXPECT_FALSE(dict.containsKey("Orange"));

    const int* value = dict.findValue("Banana");
    ASSERT_NE(value, nullptr);
    EXPECT_EQ(*value, 20);
}


TEST(FixedDictionaryTest, UpdateExistingKey) {
    FixedDictionary<std::string, int, 5> dict;

    dict.insert("Apple", 10);
    dict.insert("Apple", 50);

    EXPECT_EQ(dict.size(), 1);

    const int* value = dict.findValue("Apple");
    ASSERT_NE(value, nullptr);
    EXPECT_EQ(*value, 50);
}


TEST(FixedDictionaryTest, CapacityLimit) {
    FixedDictionary<int, std::string, 2> dict;

    EXPECT_TRUE(dict.insert(1, "One"));
    EXPECT_TRUE(dict.insert(2, "Two"));

    EXPECT_FALSE(dict.insert(3, "Three"));
    EXPECT_EQ(dict.size(), 2);
}


TEST(FixedDictionaryTest, EmptyLookup) {
    FixedDictionary<std::string, int, 3> dict;

    EXPECT_FALSE(dict.containsKey("Nothing"));
    EXPECT_EQ(dict.findValue("Nothing"), nullptr);
}