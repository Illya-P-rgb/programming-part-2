#include "../public/DomainTypes.h"

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