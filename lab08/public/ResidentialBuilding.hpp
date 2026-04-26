#ifndef RESIDENTIALBUILDING_HPP
#define RESIDENTIALBUILDING_HPP

#include "Building.hpp"

class ResidentialBuilding : public Building {
protected:
    int residents_;
    bool hasElevator_;
    int parkingSpots_;

public:
    ResidentialBuilding(int id, const std::string &name, const std::string &location,
                        int floors, double area, int yearBuilt,
                        int residents, bool hasElevator, int parkingSpots);

    int getResidents() const;
    bool hasElevator() const;
    int getParkingSpots() const;

    void describe() const override;
    double calculateOperatingCost() const override;
};

#endif