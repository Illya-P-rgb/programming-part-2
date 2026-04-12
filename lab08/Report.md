# Lab 08 — Inheritance, Abstract Classes, and Polymorphism

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov
**Date:** 012.04.2026  

---

## 1 Task Description

    The topic is: Inheritance, abstract classes, and runtime polymorphism in C++.

    To acquire practical skills in constructing semantically correct class hierarchies in
C++, introducing an abstract base class, implementing runtime polymorphism through
virtual functions, using initializer lists and override, demonstrating dynamic dispatch
through a plain array of base-class pointers, and performing a basic investigation of the
virtual table of one lower-level derived class.


## 2 Brief theoretical notes

```
   In C++, public inheritance is meaningful only when one type is a specialized kind
of another. This is a subtype relation rather than a convenient way to reuse code.
    An abstract class defines the common interface of a family of objects without
allowing direct instantiation. In C++, a class becomes abstract when it contains at least
one pure virtual method.
    The purpose of an abstract base class is to define what every derived type must
be able to do. Derived classes provide the concrete implementation of that contract.
Accordingly, in this laboratory work the top-level class of the hierarchy is abstract.
    In an inheritance hierarchy, the base subobject is constructed before the derived
part of the object. Therefore, parameters of the base class must be passed through the
initializer list.
    Runtime polymorphism appears when client code works through a base-class
pointer or reference, while the actual invoked method depends on the real dynamic
type of the object.
    Dynamic dispatch in C++ is implemented through the virtual table mechanism. In
simplified form, the idea is as follows:
    • each polymorphic class has a virtual table (vtable);
    • each object of such a class contains a hidden pointer to that table;
    • when a virtual method is overridden, the corresponding table entry points to the
    derived implementation;
    • a call through a base pointer is resolved through that table at runtime.
In this laboratory work, a full low-level memory analysis is not treated as an end in
itself; however, one required task is to inspect the active vtable of a lower-level derived
class and briefly explain which virtual methods are bound there.
```

## 3 Variant specification

```text
Urban infrastructure: CityObject -> Building -> ResidentialBuilding, with a separate IndustrialBuildin
```

## 4 UML Diagram

![alt text](/home/ilya/programming-part-2/lab08/assets/UrbanInfrastructure.png)


## 5 The project structure

```
lab08/
├── /assets
    └── UrbanInfrastructure.png
├── /private
    ├── Building.cpp
    ├── CityObject.cpp
    ├── IndustrialBuilding.cpp
    └── residentialBuilding.cpp
├── /public
    ├── Building.hpp
    ├── CityObject.hpp
    ├── IndustrialBuilding.hpp
    └── IndustrialBuilding.hpp
├── /uml
    └── Diagram.puml
├── CMakeLists.txt
├── main.cpp
└── Report.md
```


### 6 Key Code fragments from all levels

```
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
```

```
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "CityObject.hpp"

class Building : public CityObject {
protected:
    int floors_;
    double area_;
    int yearBuilt_;

public:
    Building(int id, const std::string &name, const std::string &location,
             int floors, double area, int yearBuilt);

    int getFloors() const;
    double getArea() const;
    int getYearBuilt() const;

    virtual void describe() const;
};

#endif
```

```
#ifndef INDUSTRIALBUILDING_HPP
#define INDUSTRIALBUILDING_HPP

#include "Building.hpp"

class IndustrialBuilding : public Building {
protected:
    int workers_;
    std::string industryType_;
    double powerConsumption_;

public:
    IndustrialBuilding(int id, const std::string &name, const std::string &location,
                       int floors, double area, int yearBuilt,
                       int workers, const std::string &industryType, double powerConsumption);

    int getWorkers() const;
    std::string getIndustryType() const;
    double getPowerConsumption() const;

    void describe() const override;
};

#endif
```

```
#ifndef RESIDENTIALBUILDING_HPP
#define RESIDENTIALBUILDING_HPP

#include "Building.hpp"

class ResidentialBuilding : public Building {
protected:
    int residents_;
    bool hasElevator_;
    int parkingSpots_;

public:
    ResidentialBuilding(int id, const std::string &name, const std::string &location,
                        int floors, double area, int yearBuilt,
                        int residents, bool hasElevator, int parkingSpots);

    int getResidents() const;
    bool hasElevator() const;
    int getParkingSpots() const;

    void describe() const override;
};

#endif
```

## 7 A brief description of the implemented business logic

```
The implemented business logic is somewhat simple, butr servicable. I believe it's not necessary to overenjineer and add unnecessary methods and logic to the classes when the clear focus of the lab is on abstraction and polymorphism. However, some methods are still present. The industry class has 3 getters that give the user various info about the project, aame with the residential class. Buildsing class also has several getters that i believe fit the business logic. City object also has 3 getters, but i believe it doesnt really need them due to beeing an abstract class.
```

## 8 An explanation of the demo program

```
The demo program is very simple as well. In it, i declare the array of pointers to the object class, create the 2 objectsn i need, then include their pointers into the array and call the abstract method via a for loop.
```

## 8 An explanation of the demo program
```
![alt text](/home/ilya/programming-part-2/lab08/assets/image.png)
```

## 10 GNU commands

```text
gdb ./main
break main
run
next
print res
print &res
x/4gx 
```

---

### Conclusions

```
I believe the result of my work to be satisfactory. I've followed the necessary requirements, added the necessary fields and methods, and contructed a correct abstract class setup, and polymorphism algorithm.
```