#ifndef CITYOBJECT_HPP
#define CITYOBJECT_HPP

#include <string>

class CityObject {
protected:
    int id_;
    std::string name_;
    std::string location_;

public:
    CityObject(int id, const std::string &name, const std::string &location);

    virtual ~CityObject() = default;

    int getId() const;
    std::string getName() const;
    std::string getLocation() const;

    virtual void describe() const = 0;
};

#endif