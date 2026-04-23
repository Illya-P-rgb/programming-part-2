#pragma once
#include <string>

class Appliance {
protected:
    std::string name;
    int power;

public:
    Appliance(const std::string& name, int power);

    virtual void operate() const = 0;

    virtual ~Appliance();
};