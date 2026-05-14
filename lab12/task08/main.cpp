#include <iostream>
#include "DomainTypes.h"

AudioBufferResource* createRawBuffer() {
    AudioBufferResource* res = new AudioBufferResource;
    res->size = 4;
    res->rawData = new int[4]{10, 20, 30, 40};
    return res;
}

int main() {

    AudioBufferHandle handle(createRawBuffer());

    std::cout << "Audio buffer contents:\n";

    for (size_t i = 0; i < handle.get()->size; ++i) {
        std::cout << handle.get()->rawData[i] << " ";
    }

    std::cout << "\n";

    return 0;
}