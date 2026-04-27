#pragma once
#include <string>

class Device {
protected:
    std::string name;

public:
    Device(const std::string& name);

    virtual void describe() const;

    virtual ~Device();
};