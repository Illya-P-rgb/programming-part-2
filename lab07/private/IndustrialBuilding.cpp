#include "IndustrialBuilding.hpp"
#include <iostream>
#include <stdexcept>

IndustrialBuilding::IndustrialBuilding(int id, const std::string &name, const std::string &location,
                                       int floors, double area, int yearBuilt,
                                       int workers, const std::string &industryType, double powerConsumption)
    : Building(id, name, location, floors, area, yearBuilt),
      workers_(workers), industryType_(industryType), powerConsumption_(powerConsumption)
{
    if (workers_ < 0) {
        throw std::invalid_argument("Workers cannot be negative");
    }

    if (industryType_.empty()) {
        throw std::invalid_argument("Industry type cannot be empty");
    }

    if (powerConsumption_ < 0) {
        throw std::invalid_argument("Power consumption cannot be negative");
    }
}

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

double IndustrialBuilding::powerPerWorker() const {
    if (workers_ == 0) return 0.0;
    return powerConsumption_ / workers_;
}

bool IndustrialBuilding::isEnergyIntensive() const {
    return powerConsumption_ > 1000.0;
}