#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "CityObject.hpp"

class Building : public CityObject {
protected:
    int floors_;
    double area_;
    int yearBuilt_;

public:
    Building(int id, const std::string &name, const std::string &location,
             int floors, double area, int yearBuilt);

    int getFloors() const;
    double getArea() const;
    int getYearBuilt() const;

    virtual void describe() const;
    virtual double calculateOperatingCost() const = 0;
};

#endif