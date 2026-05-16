#include "../public/SampleBuffer.h"
#include <iostream>
#include <stdexcept>

SampleBuffer::SampleBuffer(std::size_t size)
    : size_(size) {
    data_ = new Sample[size_];
}

SampleBuffer::~SampleBuffer() {
    delete[] data_;
}

SampleBuffer::SampleBuffer(const SampleBuffer& other)
    : size_(other.size_) {

    data_ = new Sample[size_];

    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

SampleBuffer& SampleBuffer::operator=(const SampleBuffer& other) {
    if (this != &other) {

        delete[] data_;

        size_ = other.size_;
        data_ = new Sample[size_];

        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    return *this;
}

std::size_t SampleBuffer::size() const {
    return size_;
}

Sample& SampleBuffer::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("SampleBuffer index out of range");
    }

    return data_[index];
}

const Sample& SampleBuffer::operator[](std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("SampleBuffer index out of range");
    }

    return data_[index];
}

void SampleBuffer::fillSample(std::size_t index, int amplitude, double timestamp) {
    if (index >= size_) {
        throw std::out_of_range("SampleBuffer fill index out of range");
    }

    data_[index] = Sample(amplitude, timestamp);
}

void SampleBuffer::print() const {
    for (std::size_t i = 0; i < size_; ++i) {
        std::cout << "Sample " << i
                  << ": amplitude = " << data_[i].getAmplitude()
                  << ", timestamp = " << data_[i].getTimestamp()
                  << "s\n";
    }
}