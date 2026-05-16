#include <iostream>
#include <memory>
#include "DomainTypes.h"

int main() {

    std::shared_ptr<Effect> reverb =
        std::make_shared<Effect>("Reverb");

    std::cout << "\nInitial use_count: "
              << reverb.use_count()
              << "\n";

    Track track1("Vocals", reverb);
    Track track2("Guitar", reverb);

    std::cout << "\nAfter assigning to tracks:\n";
    track1.printStatus();
    track2.printStatus();

    {
        Track track3("Drums", reverb);

        std::cout << "\nAfter temporary track:\n";
        track3.printStatus();

        std::cout << "Current use_count: "
                  << reverb.use_count()
                  << "\n";
    }

    std::cout << "\nAfter temporary track destruction:\n";
    std::cout << "Current use_count: "
              << reverb.use_count()
              << "\n";

    std::cout << "\nShared effect processing:\n";
    reverb->process();

    return 0;
}