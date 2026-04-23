#include "../public/InputDevice.hpp"
#include <iostream>

InputDevice::InputDevice(const std::string& name)
    : Device(name) {}

void InputDevice::describe() const {
    std::cout << "Input Device: " << name << std::endl;
}