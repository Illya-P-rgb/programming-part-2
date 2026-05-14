#ifndef SAMPLEBUFFER_H
#define SAMPLEBUFFER_H

#include "DomainTypes.h"
#include <cstddef>

class SampleBuffer {
private:
    Sample* data_;
    std::size_t size_;

public:
    explicit SampleBuffer(std::size_t size);

    ~SampleBuffer();
    SampleBuffer(const SampleBuffer& other);
    SampleBuffer& operator=(const SampleBuffer& other);

    SampleBuffer(SampleBuffer&& other) noexcept;
    SampleBuffer& operator=(SampleBuffer&& other) noexcept;

    std::size_t size() const;

    Sample& operator[](std::size_t index);
    const Sample& operator[](std::size_t index) const;

    void fillSample(std::size_t index, int amplitude, double timestamp);

    void print() const;
};

#endif