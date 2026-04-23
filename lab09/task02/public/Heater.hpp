#pragma once
#include "Appliance.hpp"

class Heater : public virtual Appliance {
protected:
    int temperature;

public:
    Heater(const std::string& name, int power, int temp);

    void operate() const override;
};