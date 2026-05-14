#include "../public/DomainTypes.h"
#include <iostream>

Sample::Sample() : amplitude_(0), timestamp_(0.0) {}

Sample::Sample(int amplitude, double timestamp)
    : amplitude_(amplitude), timestamp_(timestamp) {}

int Sample::getAmplitude() const { return amplitude_; }
double Sample::getTimestamp() const { return timestamp_; }

void releaseAudioBuffer(AudioBufferResource* res) {
    if (!res) return;

    std::cout << "[AudioSystem] Releasing audio buffer of size "
              << res->size << std::endl;

    delete[] res->rawData;
    delete res;
}

AudioBufferHandle::AudioBufferHandle(AudioBufferResource* res)
    : buffer_(res, releaseAudioBuffer) {}

AudioBufferResource* AudioBufferHandle::get() const {
    return buffer_.get();
}