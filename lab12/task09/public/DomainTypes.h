#ifndef DOMAINTYPES_H
#define DOMAINTYPES_H

#include <memory>
#include <string>

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

class Effect {
private:
    std::string effectName_;

public:
    explicit Effect(const std::string& name);

    std::string getName() const;
    void process() const;
};

class Track {
private:
    std::string trackName_;
    std::shared_ptr<Effect> effect_;

public:
    Track(const std::string& trackName,
          std::shared_ptr<Effect> effect);

    void printStatus() const;

    std::shared_ptr<Effect> getEffect() const;
};

#endif