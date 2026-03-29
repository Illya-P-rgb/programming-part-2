#include "SupportAgent.hpp"

SupportAgent::SupportAgent() : id(0), name(""), department("") {}

SupportAgent::SupportAgent(int id, const std::string& name, const std::string& department)
    : id(id), name(name), department(department) {}

int SupportAgent::getId() const {
    return id;
}

std::string SupportAgent::getName() const {
    return name;
}

std::string SupportAgent::getDepartment() const {
    return department;
}

void SupportAgent::setDepartment(const std::string& dept) {
    department = dept;
}