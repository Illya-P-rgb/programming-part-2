#include "../public/Cooler.hpp"
#include <iostream>

Cooler::Cooler(const std::string& name, int power, int level)
    : Appliance(name, power), coolingLevel(level) {}

void Cooler::operate() const {
    std::cout << name << " cooling at level " << coolingLevel << "\n";
}