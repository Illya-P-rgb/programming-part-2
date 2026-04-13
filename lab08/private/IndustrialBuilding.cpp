#include "IndustrialBuilding.hpp"
#include <iostream>

IndustrialBuilding::IndustrialBuilding(int id, const std::string &name, const std::string &location,
                                       int floors, double area, int yearBuilt,
                                       int workers, const std::string &industryType, double powerConsumption)
    : Building(id, name, location, floors, area, yearBuilt),
      workers_(workers), industryType_(industryType), powerConsumption_(powerConsumption) {}

int IndustrialBuilding::getWorkers() const {
    return workers_;
}

std::string IndustrialBuilding::getIndustryType() const {
    return industryType_;
}

double IndustrialBuilding::getPowerConsumption() const {
    return powerConsumption_;
}

void IndustrialBuilding::describe() const {
    std::cout << "Industrial Building: " << name_
              << ", workers: " << workers_
              << ", industry: " << industryType_
              << ", power: " << powerConsumption_ << std::endl;
}