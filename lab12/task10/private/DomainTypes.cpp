#include "../public/DomainTypes.h"

BadEffect::BadEffect(const std::string& name)
    : name_(name) {}

BadEffect::~BadEffect() {
    std::cout << "BadEffect destroyed: " << name_ << "\n";
}

void BadEffect::setTrack(std::shared_ptr<BadTrack> track) {
    track_ = std::move(track);
}

BadTrack::BadTrack(const std::string& name)
    : name_(name) {}

BadTrack::~BadTrack() {
    std::cout << "BadTrack destroyed: " << name_ << "\n";
}

void BadTrack::setEffect(std::shared_ptr<BadEffect> effect) {
    effect_ = std::move(effect);
}

Effect::Effect(const std::string& name)
    : name_(name) {}

Effect::~Effect() {
    std::cout << "Effect destroyed: " << name_ << "\n";
}

void Effect::setTrack(std::shared_ptr<Track> track) {
    track_ = track;
}

void Effect::printLinkedTrack() const {
    auto locked = track_.lock();

    if (locked) {
        std::cout << "Effect linked track exists\n";
    } else {
        std::cout << "Track expired\n";
    }
}

Track::Track(const std::string& name)
    : name_(name) {}

Track::~Track() {
    std::cout << "Track destroyed: " << name_ << "\n";
}

void Track::setEffect(std::shared_ptr<Effect> effect) {
    effect_ = std::move(effect);
}

BadNode::BadNode(int val)
    : value(val) {}

BadNode::~BadNode() {
    std::cout << "BadNode destroyed: " << value << "\n";
}

GoodNode::GoodNode(int val)
    : value(val) {}

GoodNode::~GoodNode() {
    std::cout << "GoodNode destroyed: " << value << "\n";
}