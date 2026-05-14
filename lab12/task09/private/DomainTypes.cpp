#include "../public/DomainTypes.h"
#include <iostream>

Sample::Sample()
    : amplitude_(0), timestamp_(0.0) {}

Sample::Sample(int amplitude, double timestamp)
    : amplitude_(amplitude), timestamp_(timestamp) {}

int Sample::getAmplitude() const {
    return amplitude_;
}

double Sample::getTimestamp() const {
    return timestamp_;
}

Effect::Effect(const std::string& name)
    : effectName_(name) {
    std::cout << "Effect created: " << effectName_ << "\n";
}

std::string Effect::getName() const {
    return effectName_;
}

void Effect::process() const {
    std::cout << "Processing effect: " << effectName_ << "\n";
}

Track::Track(const std::string& trackName,
             std::shared_ptr<Effect> effect)
    : trackName_(trackName),
      effect_(std::move(effect)) {}

void Track::printStatus() const {
    std::cout << "Track: " << trackName_
              << " | Effect: "
              << effect_->getName()
              << " | use_count: "
              << effect_.use_count()
              << "\n";
}

std::shared_ptr<Effect> Track::getEffect() const {
    return effect_;
}