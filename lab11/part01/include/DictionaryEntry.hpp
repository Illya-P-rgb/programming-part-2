#ifndef DICTIONARYENTRY_HPP
#define DICTIONARYENTRY_HPP

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
};

#endif