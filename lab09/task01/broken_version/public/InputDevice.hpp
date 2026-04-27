#pragma once
#include "Device.hpp"

class InputDevice : public Device {
public:
    InputDevice(const std::string& name);

    void describe() const override;
};