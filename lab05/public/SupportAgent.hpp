#ifndef SUPPORT_AGENT_HPP
#define SUPPORT_AGENT_HPP

#include <string>

class SupportAgent {
private:
    int id;
    std::string name;

public:
    SupportAgent();
    SupportAgent(int id, const std::string& name);

    int getId() const;
};

#endif