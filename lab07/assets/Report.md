# Lab 07 — Relationships Between Classes: Inheritance

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov
**Date:** 07.04.2026  

---

## Task Description

To acquire practical skills in constructing semantically correct class hierarchies in
C++, implementing multilevel inheritance without abstract classes and multiple inheritance, using initializer lists, override, final, =default, and =delete, and analyzing
how inherited and newly introduced state form a single object.


## Brief theoretical notes

```
    In C++, public inheritance is used when one type is a specialized kind of another.
This relationship is expressed through public inheritance.

    This notation does not merely indicate reuse of part of the code. It means that Truck
must preserve the meaning of the base type Vehicle. If the model actually describes a
“has” or “uses” relationship, inheritance is no longer natural in that context.

    For this laboratory work, it is important not only to create one base class and one
derived class, but also to build a complete vertical chain of refinement.

    Each level of such a hierarchy must add its own state and its own role in the model.
This laboratory work is not reduced to a mechanical chain of classes; the goal is to see
how the problem domain is genuinely decomposed into base and derived types
```

## Variant specification

```text
Urban infrastructure: CityObject -> Building -> ResidentialBuilding, with a separate IndustrialBuildin
```

## UML DIagram

![alt text](/home/ilya/programming-part-2/lab07/assets/lab07.png)


## CMake project structure

```
lab02/
├── /assets
    └── lab07.png
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


### Key Code fragments from all levels

```
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

    void relocate(const std::string& newLocation);
};
```

```
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

    void describe() const override;

    double calculateDensity() const;
    bool isHistoric() const;
};
```

```
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

    double powerPerWorker() const;
    bool isEnergyIntensive() const;
};
```

```
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

    double averageResidentsPerFloor() const;
    bool hasParkingAvailability() const;
};
```

## An example of object creation in main

```
Building b(2, "Office Building", "Downtown", 10, 2500.5, 2005);
```


---

## Sizeof analysis

```
Size of CityObject: 80
Size of Building: 104
Size of ResidentialBuilding: 112
Size of IndustrialBuilding: 144

In other words, sizeof analysis has confirmed that each of the following objects are bigger than the previous, therefore confirming the correct inheritance.
```
---

### Conclusions

```
I believe the result of my work to be satisfactory. I've followed the necessary requirements, added the necessary fields and methods, and contructed a correct inheritance process.
```