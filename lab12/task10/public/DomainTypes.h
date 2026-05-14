#ifndef DOMAINTYPES_H
#define DOMAINTYPES_H

#include <iostream>
#include <memory>
#include <string>

class BadTrack;

class BadEffect {
private:
    std::string name_;
    std::shared_ptr<BadTrack> track_;

public:
    explicit BadEffect(const std::string& name);
    ~BadEffect();

    void setTrack(std::shared_ptr<BadTrack> track);
};

class BadTrack {
private:
    std::string name_;
    std::shared_ptr<BadEffect> effect_;

public:
    explicit BadTrack(const std::string& name);
    ~BadTrack();

    void setEffect(std::shared_ptr<BadEffect> effect);
};

class Track;

class Effect {
private:
    std::string name_;
    std::weak_ptr<Track> track_;

public:
    explicit Effect(const std::string& name);
    ~Effect();

    void setTrack(std::shared_ptr<Track> track);
    void printLinkedTrack() const;
};

class Track {
private:
    std::string name_;
    std::shared_ptr<Effect> effect_;

public:
    explicit Track(const std::string& name);
    ~Track();

    void setEffect(std::shared_ptr<Effect> effect);
};

class BadNode {
public:
    int value;
    std::shared_ptr<BadNode> next;
    std::shared_ptr<BadNode> previous;

    explicit BadNode(int val);
    ~BadNode();
};

class GoodNode {
public:
    int value;
    std::shared_ptr<GoodNode> next;
    std::weak_ptr<GoodNode> previous;

    explicit GoodNode(int val);
    ~GoodNode();
};

#endif