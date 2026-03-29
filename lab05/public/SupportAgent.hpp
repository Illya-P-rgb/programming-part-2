#ifndef SUPPORT_AGENT_HPP
#define SUPPORT_AGENT_HPP

#include <string>

class SupportAgent {
private:
    int id;
    std::string name;
    std::string department;

public:
    SupportAgent();
    SupportAgent(int id, const std::string& name, const std::string& department);

    int getId() const;
    std::string getName() const;
    std::string getDepartment() const;

    void setDepartment(const std::string& dept);
};

#endif