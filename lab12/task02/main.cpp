#include <iostream>
#include "public/DomainTypes.h"

int main() {
    const int sampleCount = 5;

    Sample* samples = new Sample[sampleCount];

    for (int i = 0; i < sampleCount; ++i) {
        samples[i] = Sample(i * 100, i * 0.25);
    }

    std::cout << "Audio sample data:\n";

    for (int i = 0; i < sampleCount; ++i) {
        std::cout << "Sample " << i
                  << ": amplitude = " << samples[i].getAmplitude()
                  << ", timestamp = " << samples[i].getTimestamp()
                  << "s\n";
    }

    delete[] samples;

    return 0;
}