#include <iostream>
#include <memory>
#include "DomainTypes.h"

int main() {

    std::unique_ptr<Sample> samplePtr =
        std::make_unique<Sample>(500, 1.25);

    std::cout << "Single managed sample:\n";
    std::cout << "Amplitude: " << samplePtr->getAmplitude()
              << ", Timestamp: " << samplePtr->getTimestamp()
              << "s\n";

    std::unique_ptr<Sample> movedSample = std::move(samplePtr);

    std::cout << "\nMoved sample:\n";
    std::cout << "Amplitude: " << movedSample->getAmplitude()
              << "\n";

    std::unique_ptr<Sample[]> sampleArray =
        std::make_unique<Sample[]>(3);

    sampleArray[0] = Sample(100, 0.1);
    sampleArray[1] = Sample(200, 0.2);
    sampleArray[2] = Sample(300, 0.3);

    std::cout << "\nSample array:\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << "Sample " << i
                  << ": amplitude = "
                  << sampleArray[i].getAmplitude()
                  << ", timestamp = "
                  << sampleArray[i].getTimestamp()
                  << "s\n";
    }

    AudioTrack track(
        std::make_unique<Sample>(900, 2.5)
    );

    std::cout << "\nAudioTrack resource:\n";
    track.printCurrentSample();

    return 0;
}