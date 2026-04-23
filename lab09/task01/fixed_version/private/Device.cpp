#include "../public/Device.hpp"
#include <iostream>

Device::Device(const std::string& name) : name(name) {}

void Device::describe() const {
    std::cout << "Device: " << name << std::endl;
}

Device::~Device() {}