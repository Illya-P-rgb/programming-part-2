#include <iostream>

#include "CityObject.hpp"
#include "Building.hpp"
#include "ResidentialBuilding.hpp"
#include "IndustrialBuilding.hpp"

int main() {
    CityObject* objects[2];
    Building* buildings[2];

    std::cout << "-" << std::endl;

    ResidentialBuilding res(3, "Apartment Block", "Suburbs",
                            5, 1200.0, 2010,
                            100, true, 20);


    IndustrialBuilding ind(4, "Factory Zone", "Industrial Area",
                           3, 5000.0, 1998,
                           200, "Manufacturing", 1500.0);
    objects[0] = &res;
    objects[1] = &ind;
    
    for (int i = 0; i < 2; i++) {
    objects[i]->describe();
    }

    buildings[0] = &res;
    buildings[1] = &ind;

    for (auto b : buildings) {
     std::cout << b->calculateOperatingCost() << std::endl;
    }

    std::cout << "-" << std::endl;

    std::cout << "Size of CityObject: " << sizeof(CityObject) << std::endl;
    std::cout << "Size of Building: " << sizeof(Building) << std::endl;
    std::cout << "Size of ResidentialBuilding: " << sizeof(ResidentialBuilding) << std::endl;
    std::cout << "Size of IndustrialBuilding: " << sizeof(IndustrialBuilding) << std::endl;

    return 0;
}