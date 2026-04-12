#include "Building.hpp"
#include <iostream>

Building::Building(int id, const std::string &name, const std::string &location,
                   int floors, double area, int yearBuilt)
    : CityObject(id, name, location),
      floors_(floors), area_(area), yearBuilt_(yearBuilt) {}

int Building::getFloors() const {
    return floors_;
}

double Building::getArea() const {
    return area_;
}

int Building::getYearBuilt() const {
    return yearBuilt_;
}

void Building::describe() const {
    std::cout << "Building: " << name_
              << ", floors: " << floors_
              << ", area: " << area_
              << ", built: " << yearBuilt_ << std::endl;
}
