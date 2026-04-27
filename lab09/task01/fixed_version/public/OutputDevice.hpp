#pragma once
#include "Device.hpp"

class OutputDevice : public virtual Device {
public:
    OutputDevice(const std::string& name);

    void describe() const override;
};