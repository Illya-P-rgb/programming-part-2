#include <iostream>
#include "public/SampleBuffer.h"

int main() {
    SampleBuffer buffer(5);

    for (std::size_t i = 0; i < buffer.size(); ++i) {
        buffer.fillSample(i, static_cast<int>(i * 150), i * 0.25);
    }

    std::cout << "Audio Sample Buffer:\n";
    buffer.print();

    return 0;
}