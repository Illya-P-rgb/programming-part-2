#include <iostream>
#include <memory>
#include "DomainTypes.h"

int main() {

    std::cout << "bad track\n";
    {
        auto track = std::make_shared<BadTrack>("MainTrack");
        auto effect = std::make_shared<BadEffect>("Reverb");

        track->setEffect(effect);
        effect->setTrack(track);

        std::cout << "Track use_count: " << track.use_count() << "\n";
        std::cout << "Effect use_count: " << effect.use_count() << "\n";
    }

    std::cout << "\nmemory leak above if there are no destructors\n";

    std::cout << "\ngood track\n";
    {
        auto track = std::make_shared<Track>("FixedTrack");
        auto effect = std::make_shared<Effect>("Delay");

        track->setEffect(effect);
        effect->setTrack(track);

        effect->printLinkedTrack();
    }

    std::cout << "\nbad list\n";
    {
        auto node1 = std::make_shared<BadNode>(1);
        auto node2 = std::make_shared<BadNode>(2);

        node1->next = node2;
        node2->previous = node1;
    }

    std::cout << "\nIf BadNode destructor missing\n";

    std::cout << "\n good list\n";
    {
        auto node1 = std::make_shared<GoodNode>(1);
        auto node2 = std::make_shared<GoodNode>(2);

        node1->next = node2;
        node2->previous = node1;
    }

    return 0;
}