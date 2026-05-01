#ifndef FIXEDDICTIONARY_HPP
#define FIXEDDICTIONARY_HPP

#include "DictionaryEntry.hpp"
#include <cstddef>

template <typename Key, typename Value, std::size_t N>
class FixedDictionary {
private:
    DictionaryEntry<Key, Value> entries_[N];
    std::size_t currentSize_;

public:
    FixedDictionary()
        : currentSize_(0) {}

    bool insert(const Key& key, const Value& value) {
        if (currentSize_ >= N) {
            return false;
        }

        for (std::size_t i = 0; i < currentSize_; ++i) {
            if (entries_[i].getKey() == key) {
                entries_[i].setValue(value);
                return true;
            }
        }

        entries_[currentSize_] = DictionaryEntry<Key, Value>(key, value);
        ++currentSize_;
        return true;
    }

    bool containsKey(const Key& key) const {
        for (std::size_t i = 0; i < currentSize_; ++i) {
            if (entries_[i].getKey() == key) {
                return true;
            }
        }
        return false;
    }

    const Value* findValue(const Key& key) const {
        for (std::size_t i = 0; i < currentSize_; ++i) {
            if (entries_[i].getKey() == key) {
                return &entries_[i].getValue();
            }
        }
        return nullptr;
    }

    std::size_t size() const {
        return currentSize_;
    }

    constexpr std::size_t capacity() const {
        return N;
    }
};

#endif