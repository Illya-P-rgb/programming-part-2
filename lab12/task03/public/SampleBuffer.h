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

    std::size_t size() const;

    Sample& operator[](std::size_t index);
    const Sample& operator[](std::size_t index) const;

    void fillSample(std::size_t index, int amplitude, double timestamp);

    void print() const;
};

#endif