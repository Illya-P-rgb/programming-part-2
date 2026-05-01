#include <iostream>
#include <string>

#include "FixedDictionary.hpp"

int main() {
    FixedDictionary<std::string, int, 3> dictionary;

    std::cout << "Demo: \n\n";

    dictionary.insert("Apple", 10);
    dictionary.insert("Banana", 20);
    dictionary.insert("Orange", 15);

    std::cout << "Current size: " << dictionary.size()
              << "/" << dictionary.capacity() << "\n";

    if (const int* value = dictionary.findValue("Banana")) {
        std::cout << "Banana -> " << *value << "\n";
    }

    if (!dictionary.containsKey("Grape")) {
        std::cout << "Grape not found.\n";
    }

    dictionary.insert("Banana", 25);

    if (const int* updated = dictionary.findValue("Banana")) {
        std::cout << "Banana updated -> " << *updated << "\n";
    }

    bool inserted = dictionary.insert("Grape", 30);

    if (!inserted) {
        std::cout << "Insertion failed: dictionary is full.\n";
    }

    return 0;
}