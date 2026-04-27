#pragma once
#include "InputDevice.hpp"
#include "OutputDevice.hpp"

class TouchDisplay : public InputDevice, public OutputDevice {
public:
    TouchDisplay(const std::string& name);

    void describe() const override;
};