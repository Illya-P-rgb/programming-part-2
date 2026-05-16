#ifndef DOMAINTYPES_H
#define DOMAINTYPES_H

#include <memory>

class Sample {
private:
    int amplitude_;
    double timestamp_;

public:
    Sample();
    Sample(int amplitude, double timestamp);

    int getAmplitude() const;
    double getTimestamp() const;
};

class AudioTrack {
private:
    std::unique_ptr<Sample> currentSample_;

public:
    explicit AudioTrack(std::unique_ptr<Sample> sample);

    AudioTrack(const AudioTrack&) = delete;
    AudioTrack& operator=(const AudioTrack&) = delete;

    AudioTrack(AudioTrack&&) noexcept = default;
    AudioTrack& operator=(AudioTrack&&) noexcept = default;

    void printCurrentSample() const;
};

#endif