#include "../public/OutputDevice.hpp"
#include <iostream>

OutputDevice::OutputDevice(const std::string& name)
    : Device(name) {}

void OutputDevice::describe() const {
    std::cout << "Output Device: " << name << std::endl;
}