#pragma once
#include "Appliance.hpp"

class Humidifier : public virtual Appliance {
protected:
    int humidity;

public:
    Humidifier(const std::string& name, int power, int humidity);

    void operate() const override;
};