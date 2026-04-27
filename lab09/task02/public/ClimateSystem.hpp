#pragma once
#include "Heater.hpp"
#include "Cooler.hpp"
#include "Humidifier.hpp"

class ClimateSystem : public Heater, public Cooler, public Humidifier {
public:
    ClimateSystem(const std::string& name, int power,
                  int temp, int level, int humidity);

    void operate() const override;
};