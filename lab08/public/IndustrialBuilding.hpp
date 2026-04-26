#ifndef INDUSTRIALBUILDING_HPP
#define INDUSTRIALBUILDING_HPP

#include "Building.hpp"

class IndustrialBuilding : public Building {
protected:
    int workers_;
    std::string industryType_;
    double powerConsumption_;

public:
    IndustrialBuilding(int id, const std::string &name, const std::string &location,
                       int floors, double area, int yearBuilt,
                       int workers, const std::string &industryType, double powerConsumption);

    int getWorkers() const;
    std::string getIndustryType() const;
    double getPowerConsumption() const;

    void describe() const override;
    double calculateOperatingCost() const override;
};

#endif