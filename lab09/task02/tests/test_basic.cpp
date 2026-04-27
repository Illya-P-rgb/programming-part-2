#include <gtest/gtest.h>

#include "../public/Heater.hpp"
#include "../public/Cooler.hpp"
#include "../public/Humidifier.hpp"
#include "../public/ClimateSystem.hpp"

TEST(Basic, ConstructionAndOperate) {
    Heater h("Heater A", 100, 25);
    Cooler c("Cooler B", 80, 3);
    Humidifier u("Humidifier C", 70, 60);
    ClimateSystem sys("Smart System", 150, 22, 3, 55);

    Appliance* arr[] = { &h, &c, &u, &sys };

    for (auto a : arr) {
        a->operate();
    }

    SUCCEED();
}