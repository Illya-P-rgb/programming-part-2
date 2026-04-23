#include "../public/TouchDisplay.hpp"
#include <iostream>

TouchDisplay::TouchDisplay(const std::string& name)
    : Device(name),        // 🔥 REQUIRED for virtual base
      InputDevice(name),
      OutputDevice(name) {}

void TouchDisplay::describe() const {
    std::cout << "Touch Display: " << name << std::endl;
}