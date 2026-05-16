#include <iostream>
#include <utility>
#include "public/DomainTypes.h"
#include "public/SimplePtr.h"

int main() {
    SimplePtr<Sample> samplePtr(new Sample(500, 1.25));

    std::cout << "Managed Sample:\n";
    std::cout << "Amplitude: " << samplePtr->getAmplitude() << "\n";
    std::cout << "Timestamp: " << samplePtr->getTimestamp() << "s\n";

    SimplePtr<Sample> movedPtr(std::move(samplePtr));

    std::cout << "\nMoved Sample:\n";
    std::cout << "Amplitude: " << movedPtr->getAmplitude() << "\n";
    std::cout << "Timestamp: " << movedPtr->getTimestamp() << "s\n";

    return 0;
}