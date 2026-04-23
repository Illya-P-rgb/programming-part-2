#pragma once
#include "Device.hpp"

class InputDevice : public virtual Device {
public:
    InputDevice(const std::string& name);

    void describe() const override;
};