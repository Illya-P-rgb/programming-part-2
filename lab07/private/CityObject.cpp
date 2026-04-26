#include "CityObject.hpp"
#include <stdexcept>

CityObject::CityObject(int id, const std::string &name, const std::string &location)
    : id_(id), name_(name), location_(location)
{
    if (id_ <= 0) {
        throw std::invalid_argument("ID must be positive");
    }

    if (name_.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }

    if (location_.empty()) {
        throw std::invalid_argument("Location cannot be empty");
    }
}

int CityObject::getId() const {
    return id_;
}

std::string CityObject::getName() const {
    return name_;
}

std::string CityObject::getLocation() const {
    return location_;
}

void CityObject::relocate(const std::string& newLocation) {
    if (newLocation.empty()) {
        throw std::invalid_argument("New location cannot be empty");
    }
    location_ = newLocation;
}