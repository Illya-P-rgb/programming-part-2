#include "../public/Appliance.hpp"

Appliance::Appliance(const std::string& name, int power)
    : name(name), power(power) {}

Appliance::~Appliance() {}