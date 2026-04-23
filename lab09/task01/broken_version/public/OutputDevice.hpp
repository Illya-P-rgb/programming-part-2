#pragma once
#include "Device.hpp"

class OutputDevice : public Device {
public:
    OutputDevice(const std::string& name);

    void describe() const override;
};