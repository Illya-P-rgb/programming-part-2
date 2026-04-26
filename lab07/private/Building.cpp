#include "Building.hpp"
#include <iostream>
#include <stdexcept>

Building::Building(int id, const std::string &name, const std::string &location,
                   int floors, double area, int yearBuilt)
    : CityObject(id, name, location),
      floors_(floors), area_(area), yearBuilt_(yearBuilt)
{
    if (floors_ <= 0) {
        throw std::invalid_argument("Floors must be positive");
    }

    if (area_ <= 0) {
        throw std::invalid_argument("Area must be positive");
    }

    if (yearBuilt_ <= 0) {
        throw std::invalid_argument("Year built must be positive");
    }
}

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

double Building::calculateDensity() const {
    return area_ / floors_;
}

bool Building::isHistoric() const {
    return yearBuilt_ < 1950;
}