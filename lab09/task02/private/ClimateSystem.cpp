#include "../public/ClimateSystem.hpp"
#include <iostream>

ClimateSystem::ClimateSystem(const std::string& name, int power,
                             int temp, int level, int humidity)
    : Appliance(name, power),
      Heater(name, power, temp),
      Cooler(name, power, level),
      Humidifier(name, power, humidity) {}

void ClimateSystem::operate() const {
    std::cout << name << " full climate control active:\n";
    Heater::operate();
    Cooler::operate();
    Humidifier::operate();
}