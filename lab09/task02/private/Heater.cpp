#include "../public/Heater.hpp"
#include <iostream>

Heater::Heater(const std::string& name, int power, int temp)
    : Appliance(name, power), temperature(temp) {}

void Heater::operate() const {
    std::cout << name << " heating to " << temperature << "°C\n";
}