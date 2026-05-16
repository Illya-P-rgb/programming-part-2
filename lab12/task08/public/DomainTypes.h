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

struct AudioBufferResource {
    int* rawData;
    size_t size;
};

void releaseAudioBuffer(AudioBufferResource* res);

class AudioBufferHandle {
private:
    std::unique_ptr<AudioBufferResource, void(*)(AudioBufferResource*)> buffer_;

public:
    explicit AudioBufferHandle(AudioBufferResource* res);

    AudioBufferHandle(const AudioBufferHandle&) = delete;
    AudioBufferHandle& operator=(const AudioBufferHandle&) = delete;

    AudioBufferHandle(AudioBufferHandle&&) noexcept = default;
    AudioBufferHandle& operator=(AudioBufferHandle&&) noexcept = default;

    AudioBufferResource* get() const;
};

#endif