#include <iostream>
#include <utility>
#include "public/SampleBuffer.h"

SampleBuffer createBuffer() {
    SampleBuffer temp(3);

    temp.fillSample(0, 10, 0.1);
    temp.fillSample(1, 20, 0.2);
    temp.fillSample(2, 30, 0.3);

    return temp;
}

int main() {
    SampleBuffer original(3);

    original.fillSample(0, 100, 0.1);
    original.fillSample(1, 200, 0.2);
    original.fillSample(2, 300, 0.3);

    std::cout << "Original buffer:\n";
    original.print();

    SampleBuffer copied(original);

    std::cout << "\nCopied buffer:\n";
    copied.print();

    SampleBuffer assigned(2);
    assigned = original;

    std::cout << "\nAssigned buffer:\n";
    assigned.print();

    SampleBuffer moved(std::move(original));

    std::cout << "\nMoved buffer (move constructor):\n";
    moved.print();

    std::cout << "\nOriginal after move:\n";
    original.print();

    SampleBuffer movedAssigned(1);
    movedAssigned = createBuffer();

    std::cout << "\nMove-assigned buffer:\n";
    movedAssigned.print();

    return 0;
}