#include <iostream>

#include "CityObject.hpp"
#include "Building.hpp"
#include "ResidentialBuilding.hpp"
#include "IndustrialBuilding.hpp"

int main() {
    CityObject obj(1, "Generic Object", "Center");
    obj.describe();

    std::cout << "-" << std::endl;

    Building b(2, "Office Building", "Downtown", 10, 2500.5, 2005);
    b.describe();

    std::cout << "-" << std::endl;

    ResidentialBuilding res(3, "Apartment Block", "Suburbs",
                            5, 1200.0, 2010,
                            100, true, 20);
    res.describe();

    std::cout << "-" << std::endl;

    IndustrialBuilding ind(4, "Factory Zone", "Industrial Area",
                           3, 5000.0, 1998,
                           200, "Manufacturing", 1500.0);
    ind.describe();

    std::cout << "------------------" << std::endl;

    std::cout << "Size of CityObject: " << sizeof(CityObject) << std::endl;
    std::cout << "Size of Building: " << sizeof(Building) << std::endl;
    std::cout << "Size of ResidentialBuilding: " << sizeof(ResidentialBuilding) << std::endl;
    std::cout << "Size of IndustrialBuilding: " << sizeof(IndustrialBuilding) << std::endl;

    return 0;
}