#ifndef DICTIONARYENTRY_HPP

#include <cstring>

template <typename Key, typename Value>
class DictionaryEntry {
private:
    Key key_;
    Value value_;

public:
    DictionaryEntry() = default;

    DictionaryEntry(const Key& key, const Value& value)
        : key_(key), value_(value) {}

    const Key& getKey() const {
        return key_;
    }

    const Value& getValue() const {
        return value_;
    }

    void setValue(const Value& value) {
        value_ = value;
    }

    bool keyEquals(const Key& otherKey) const {
        return key_ == otherKey;
    }
};


template <typename Value>
class DictionaryEntry<const char*, Value> {
private:
    const char* key_;
    Value value_;

public:
    DictionaryEntry() = default;

    DictionaryEntry(const char* key, const Value& value)
        : key_(key), value_(value) {}

    const char* getKey() const {
        return key_;
    }

    const Value& getValue() const {
        return value_;
    }

    void setValue(const Value& value) {
        value_ = value;
    }

    bool keyEquals(const char* otherKey) const {
        return std::strcmp(key_, otherKey) == 0;
    }
};

#endif