#include "public/Heater.hpp"
#include "public/Cooler.hpp"
#include "public/Humidifier.hpp"
#include "public/ClimateSystem.hpp"

int main() {
    Appliance* devices[4];

    devices[0] = new Heater("Heater A", 1000, 25);
    devices[1] = new Cooler("Cooler B", 800, 3);
    devices[2] = new Humidifier("Humidifier C", 500, 60);
    devices[3] = new ClimateSystem("Smart System", 2000, 22, 3, 55);

    for (int i = 0; i < 4; i++) {
        devices[i]->operate();
    }

    for (int i = 0; i < 4; i++) {
        delete devices[i];
    }

    return 0;
}