#include "ResidentialBuilding.hpp"
#include <iostream>
#include <stdexcept>

ResidentialBuilding::ResidentialBuilding(int id, const std::string &name, const std::string &location,
                                         int floors, double area, int yearBuilt,
                                         int residents, bool hasElevator, int parkingSpots)
    : Building(id, name, location, floors, area, yearBuilt),
      residents_(residents), hasElevator_(hasElevator), parkingSpots_(parkingSpots)
{
    if (residents_ < 0) {
        throw std::invalid_argument("Residents cannot be negative");
    }

    if (parkingSpots_ < 0) {
        throw std::invalid_argument("Parking spots cannot be negative");
    }
}

int ResidentialBuilding::getResidents() const {
    return residents_;
}

bool ResidentialBuilding::hasElevator() const {
    return hasElevator_;
}

int ResidentialBuilding::getParkingSpots() const {
    return parkingSpots_;
}

void ResidentialBuilding::describe() const {
    std::cout << "Residential Building: " << name_
              << ", residents: " << residents_
              << ", elevator: " << (hasElevator_ ? "yes" : "no")
              << ", parking spots: " << parkingSpots_ << std::endl;
}


double ResidentialBuilding::averageResidentsPerFloor() const {
    return static_cast<double>(residents_) / floors_;
}

bool ResidentialBuilding::hasParkingAvailability() const {
    return parkingSpots_ > 0;
}