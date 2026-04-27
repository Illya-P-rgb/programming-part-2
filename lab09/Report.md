# Lab 09 — Multiple Inheritance in C++

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov  
**Date:** 04/24/2026  

---

## The topic, objective, and problem statement

    Multiple inheritance and the diamond problem in C++

To acquire practical skills in designing class hierarchies that involve multiple inheritance in C++, understanding the causes and consequences of the diamond inheritance
problem, applying virtual inheritance as the standard solution, correctly ordering constructor calls with virtual base classes, and implementing domain models that combine
capabilities from independent class branches.

    The laboratory work consists of two tasks. The tasks are independent and use two
separate variant selection formulas.

## Brief theoretical background

C++ allows a class to have more than one direct base class. The derived class inherits
the combined interface and state of all base classes.

When two base classes define a member with the same name, the derived class contains two distinct members. Accessing the name without qualification is then ambiguous.

Ambiguity is resolved either by explicit scope resolution (A::describe()) or by
introducing a new override in C that specifies which base version to call.

The diamond problem arises when two classes B and C both inherit from the same
base class A, and a fourth class D inherits from both B and C. Without special treatment, D
contains two separate subobjects of type A.

Virtual inheritance ensures that only one shared subobject of the common base is
present in the most-derived class, regardless of how many paths in the hierarchy lead to
it.

The keyword virtual is placed in the inheritance specifier of the intermediate
classes, not in the final derived class. The compiler merges the two would-be copies into a
single shared subobject.

When virtual inheritance is used, the most-derived class is responsible for directly
constructing the virtual base. The constructor call order follows a fixed rule:
1) virtual base classes are constructed first, in depth-first, left-to-right order;
2) non-virtual base classes follow, in declaration order;
3) the derived class body executes last.
This means the most-derived class must include the virtual base in its initializer
list. If it does not, the virtual base is default-constructed, which may or may not be the
intended behavior.
Any initializer for the virtual base that appears in an intermediate class (such as
Student or Employee) is silently ignored when constructing an Intern. The rationale is
that there is only one copy of the virtual base and its initialization must not be duplicated.


## Selected Variants

![alt text](/home/ilya/programming-part-2/lab09/task01/fixed_version/assets/image-1.png)
![alt text](/home/ilya/programming-part-2/lab09/task02/assets/image.png)


## Task 1 diagrams:

Wrong diagram:
![alt text](/home/ilya/programming-part-2/lab09/task01/broken_version/assets/wrong_diagram.png)

Right diagram: 
![alt text](/home/ilya/programming-part-2/lab09/task01/fixed_version/assets/correct_diagram.png)

## Task 1 code fragments:

```
#pragma once
#include <string>

class Device {
protected:
    std::string name;

public:
    Device(const std::string& name);

    virtual void describe() const;

    virtual ~Device();
};
```

```
#include "public/TouchDisplay.hpp"

int main() {
    TouchDisplay td("Smart Touch");

    td.describe();

    return 0;
}
```

```
#include "Device.hpp"
#include <iostream>

Device::Device(const std::string& name) : name(name) {}

void Device::describe() const {
    std::cout << "Device: " << name << std::endl;
}

Device::~Device() {}
```

## Task 1: Constructor changes

```text
In the corrected version, virtual inheritance is used to avoid duplication of the base class.

In the incorrect version, each intermediate class independently initialized Device, which resulted in two separate instances of the base class in TouchDisplay. This caused ambiguity when accessing base class methods.

In the corrected version, both intermediate classes inherit Device virtually, and the constructor of the most derived class (TouchDisplay) explicitly initializes the Device base class using an initializer list. This ensures that only a single shared instance of Device is created.

As a result, ambiguity is eliminated, and the program behaves correctly.
```

## Task 2: Diagram

![alt text](/home/ilya/programming-part-2/lab09/task02/assets/Diagram.png)

## Task 2: Code fragments

```
#pragma once
#include <string>

class Appliance {
protected:
    std::string name;
    int power;

public:
    Appliance(const std::string& name, int power);

    virtual void operate() const = 0;

    virtual ~Appliance();
};
```

```
#include "../public/Appliance.hpp"

Appliance::Appliance(const std::string& name, int power)
    : name(name), power(power) {}

Appliance::~Appliance() {}
```

```
#include "public/Heater.hpp"
#include "public/Cooler.hpp"
#include "public/Humidifier.hpp"
#include "public/ClimateSystem.hpp"

int main() {
    Appliance* devices[4];

    devices[0] = new Heater("Heater A", 1000, 25);
    devices[1] = new Cooler("Cooler B", 800, 3);
    devices[2] = new Humidifier("Humidifier C", 500, 60);
    devices[3] = new ClimateSystem("Smart System", 2000, 22, 3, 55);

    for (int i = 0; i < 4; i++) {
        devices[i]->operate();
    }

    for (int i = 0; i < 4; i++) {
        delete devices[i];
    }

    return 0;
}
```

```
#pragma once
#include "Heater.hpp"
#include "Cooler.hpp"
#include "Humidifier.hpp"

class ClimateSystem : public Heater, public Cooler, public Humidifier {
public:
    ClimateSystem(const std::string& name, int power,
                  int temp, int level, int humidity);

    void operate() const override;
};
```

```
#pragma once
#include "Appliance.hpp"

class Cooler : public virtual Appliance {
protected:
    int coolingLevel;

public:
    Cooler(const std::string& name, int power, int level);

    void operate() const override;
};
```

```
#pragma once
#include "Appliance.hpp"

class Heater : public virtual Appliance {
protected:
    int temperature;

public:
    Heater(const std::string& name, int power, int temp);

    void operate() const override;
};
```

```
#pragma once
#include "Appliance.hpp"

class Humidifier : public virtual Appliance {
protected:
    int humidity;

public:
    Humidifier(const std::string& name, int power, int humidity);

    void operate() const override;
};
```

## Task 2: Demo explanation

```
The demo program creates objects of different derived classes (Heater, Cooler, Humidifier, ClimateSystem) and stores them in an array of base-class pointers (Appliance*). This allows all objects to be accessed through a common interface. A loop then calls the same virtual method (operate()) for each element, and due to polymorphism, the correct implementation is executed depending on the actual object type.

An array of pointers is used instead of an array of objects to avoid object slicing. If objects were stored directly as Appliance, only the base part would be preserved, and the specific behavior of derived classes would be lost. Using pointers ensures that the full objects are referenced, allowing virtual functions to work correctly and enabling runtime polymorphism.
```

## Structure

```text
lab09/
├── task01
    ├── broken_version/
    └── fixed_version/
└── task02
    ├── assets/
    ├── private/
    ├── public/
    └── main.cpp
```

### Observations and Conclusion

This lab seemed complicated at first, but eventually i managed to come out on top. In task 1, i had to make a broken version of a project, to demonstrate the diamond problem, and then make another directory with this exact task, but done correctly. The diamond problem is solved by offloading the task of creating the base class onto the most derived class' constructor, along with some other minor additions. The second task was a full project, and it was meant to demonstrate multiple inheritance hirarchy, along with virtual inheritance.

---
