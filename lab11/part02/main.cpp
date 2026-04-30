#include <iostream>
#include <string>

#include "FixedDictionary.hpp"

int main() {
    std::cout << "Standard Dictionary:\n";

    FixedDictionary<std::string, int, 3> standardDict;
    standardDict.insert("Apple", 10);
    standardDict.insert("Banana", 20);

    if (const int* value = standardDict.findValue("Banana")) {
        std::cout << "Banana -> " << *value << "\n";
    }

    std::cout << "\nSpecialized const char* Dictionary:\n";

    FixedDictionary<const char*, int, 3> cStringDict;

    cStringDict.insert("Orange", 15);
    cStringDict.insert("Grape", 30);

    if (const int* value = cStringDict.findValue("Orange")) {
        std::cout << "Orange -> " << *value << "\n";
    }

    std::cout << "\nCompiler investigation:\n";
    std::cout << "Size of std::string dictionary: "
              << sizeof(standardDict) << " bytes\n";
    std::cout << "Size of const char* dictionary: "
              << sizeof(cStringDict) << " bytes\n";
// clang++ -std=c++20 -Iinclude -Xclang -ast-dump -fsyntax-only main.cpp > ast_dump.txt <- спочатку це
// clang++ -std=c++20 -Iinclude -Xclang -fdump-record-layouts -c main.cpp > layouts.txt <- потім це
    return 0;
}