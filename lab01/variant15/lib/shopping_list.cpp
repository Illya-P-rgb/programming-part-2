#include "shopping_list.hpp"
#include <algorithm>

void ShoppingList::add(const std::string& item) {
    items_.push_back(item);
}

void ShoppingList::remove(const std::string& item) {
    auto it = std::find(items_.begin(), items_.end(), item);
    if (it != items_.end()) items_.erase(it);
}

int ShoppingList::count() const {
    return items_.size();
}