#include "../public/Humidifier.hpp"
#include <iostream>

Humidifier::Humidifier(const std::string& name, int power, int humidity)
    : Appliance(name, power), humidity(humidity) {}

void Humidifier::operate() const {
    std::cout << name << " humidifying to " << humidity << "%\n";
}