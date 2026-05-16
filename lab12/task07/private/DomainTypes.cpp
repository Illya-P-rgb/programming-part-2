#include "../public/DomainTypes.h"
#include <iostream>

Sample::Sample()
    : amplitude_(0), timestamp_(0.0) {}

Sample::Sample(int amplitude, double timestamp)
    : amplitude_(amplitude), timestamp_(timestamp) {}

int Sample::getAmplitude() const {
    return amplitude_;
}

double Sample::getTimestamp() const {
    return timestamp_;
}

AudioTrack::AudioTrack(std::unique_ptr<Sample> sample)
    : currentSample_(std::move(sample)) {}

void AudioTrack::printCurrentSample() const {
    if (!currentSample_) {
        std::cout << "(no sample loaded)\n";
        return;
    }

    std::cout << "Current Sample -> Amplitude: "
              << currentSample_->getAmplitude()
              << ", Timestamp: "
              << currentSample_->getTimestamp()
              << "s\n";
}