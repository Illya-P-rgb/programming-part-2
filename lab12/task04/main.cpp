#include <iostream>
#include "public/SampleBuffer.h"

int main() {
    SampleBuffer original(3);

    original.fillSample(0, 100, 0.1);
    original.fillSample(1, 200, 0.2);
    original.fillSample(2, 300, 0.3);

    std::cout << "Original buffer:\n";
    original.print();

    SampleBuffer copied(original);

    std::cout << "\nCopied buffer (copy constructor):\n";
    copied.print();

    SampleBuffer assigned(2);
    assigned = original;

    std::cout << "\nAssigned buffer (copy assignment):\n";
    assigned.print();

    return 0;
}