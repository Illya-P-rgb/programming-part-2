#include "CityObject.hpp"
#include <iostream>

CityObject::CityObject(int id, const std::string &name, const std::string &location)
    : id_(id), name_(name), location_(location) {}

int CityObject::getId() const {
    return id_;
}

std::string CityObject::getName() const {
    return name_;
}

std::string CityObject::getLocation() const {
    return location_;
}

