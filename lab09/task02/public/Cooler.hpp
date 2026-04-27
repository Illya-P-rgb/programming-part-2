#pragma once
#include "Appliance.hpp"

class Cooler : public virtual Appliance {
protected:
    int coolingLevel;

public:
    Cooler(const std::string& name, int power, int level);

    void operate() const override;
};