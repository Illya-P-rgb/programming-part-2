#pragma once
#include <string>
#include <vector>

class ShoppingList {
public:
    void add(const std::string& item);
    void remove(const std::string& item);
    int count() const;

private:
    std::vector<std::string> items_;
};