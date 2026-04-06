#include "SupportAgent.hpp"

SupportAgent::SupportAgent() : id(0), name("") {}

SupportAgent::SupportAgent(int id, const std::string& name)
    : id(id), name(name) {}

int SupportAgent::getId() const {
    return id;
}