# Lab 10 — Function Templates in C++

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov 
**Date:** 04/29/2026 

---

## The topic, purpose, and assignment statement

    The purpose of this laboratory work is to develop practical skills in designing and
implementing reusable function templates in C++. The work is intended to reinforce
the distinction between ordinary function overloading and parameterized algorithms,
demonstrate how template argument deduction operates in typical cases, and show how
generic code may be adapted for special situations through specialization, overload-based
customization, or simple constraints.


## brief theoretical notes

A function template describes a family of functions rather than one isolated implementation. Instead of rewriting the same algorithm for several data types, the programmer
specifies the algorithm once and leaves the concrete type substitution to the compiler.

This mechanism makes it possible to express the common structure of an operation while
preserving type safety.

In practice, not every algorithm is equally generic. Some templates work only for
types that support comparison, arithmetic, copying, output streaming, or other required
operations. Consequently, generic programming is based not on the absence of rules, but
on clearly understood requirements imposed on the template arguments. If a type does
not meet those requirements, template argument deduction or instantiation fails.

In C++, function templates participate in overload resolution together with ordinary
functions. This means that the compiler must both deduce template parameters and select
the best candidate among several possible call targets. In some cases, a general template is
sufficient; in other cases, one type requires separate handling. Such situations may be addressed by full specialization, by an ordinary overload, or, for brief introductory examples,
by lightweight constraints such as std::enable_if for arithmetic-only utilities.

Variadic function templates extend the same idea to a variable number of arguments.
They are especially useful for aggregation, printing, logging, and other helper utilities
in which the number of processed values is not fixed in advance. For this reason, they
are included in the scope of the present work as an advanced but still practical part of
function template programming.

A crucial implementation detail is that template definitions are usually placed in
header files. The compiler must see the full template definition at the point where a
concrete instantiation is required. Separating only the declaration into a header and
moving the implementation to a .cpp file is generally incorrect for templates unless
explicit instantiation is used intentionally.

## Variant specifications

Variant 6: Geometry Helpers
Objective: Develop a small header-only utility module for simple one-dimensional
and scalar geometry utilities using function templates.
Required tasks:
1) Implement square() for a generic numeric value.
2) Implement midpoint() for two values that may have different numeric types.
3) Implement distance1D() that returns the absolute distance between two
points.
Minimum testing scope:
• Test int, double, and mixed calls such as int with double.
• Include negative coordinates and coincident points.
Suggested technical focus: return-type design, mixed-type deduction, and arithmetic genericity
Variant 

## Justification

The template parameters were made to make the functions reusable for different numeric types. square() uses one template parameter, since it works with a single value, while midpoint() and distance1D() use two to allow operations between different types.

Return types were also designed to use common type deduction, which helps avoid precision loss. The main requirement is that the provided types support basic arithmetic operations like multiplication, addition, subtraction, and division. Special cases such as negative values were also covered in the code to ensure correct behavior.

## Structure

```text
lab10/
├── assets/
├── include/
    └── variant_utils.hpp
├── tests/
    └── test_variant_utils.cpp
├── CMakeLists.txt
├── main.cpp
└── Report.md
```
## Code fragments

```
#ifndef GEOMETRYUTILS_HPP
#define GEOMETRYUTILS_HPP

#include <type_traits>
#include <cmath>

namespace GeometryUtils {

template <typename T>
auto square(T value) {
    return value * value;
}

template <typename T, typename U>
auto midpoint(T a, U b) {
    using CommonType = std::common_type_t<T, U>;
    return (static_cast<CommonType>(a) + static_cast<CommonType>(b)) / static_cast<CommonType>(2);
}

template <typename T, typename U>
auto distance1D(T a, U b) {
    using CommonType = std::common_type_t<T, U>;
    return std::abs(static_cast<CommonType>(a) - static_cast<CommonType>(b));
}

}

#endif
```

```
#include <iostream>
#include "variant_utils.hpp"

int main() {
    using namespace GeometryUtils;

    std::cout << "=== Geometry Helpers Demo ===\n\n";

    std::cout << "square(5) = " << square(5) << "\n";
    std::cout << "square(2.5) = " << square(2.5) << "\n\n";

    std::cout << "midpoint(2, 6) = " << midpoint(2, 6) << "\n";
    std::cout << "midpoint(2, 5.5) = " << midpoint(2, 5.5) << "\n\n";

    std::cout << "distance1D(-4, 7) = " << distance1D(-4, 7) << "\n";
    std::cout << "distance1D(3.5, 3.5) = " << distance1D(3.5, 3.5) << "\n";

    return 0;
}
```

## test code fragments

```
#include <gtest/gtest.h>
#include "variant_utils.hpp"

using namespace GeometryUtils;

TEST(GeometryUtilsTest, SquareInt) {
    EXPECT_EQ(square(5), 25);
    EXPECT_EQ(square(-4), 16);
}

TEST(GeometryUtilsTest, SquareDouble) {
    EXPECT_DOUBLE_EQ(square(2.5), 6.25);
}

TEST(GeometryUtilsTest, MidpointInt) {
    EXPECT_EQ(midpoint(2, 6), 4);
}

TEST(GeometryUtilsTest, MidpointMixed) {
    EXPECT_DOUBLE_EQ(midpoint(2, 5.0), 3.5);
}

TEST(GeometryUtilsTest, MidpointNegative) {
    EXPECT_DOUBLE_EQ(midpoint(-4, 4), 0.0);
}

TEST(GeometryUtilsTest, DistanceInt) {
    EXPECT_EQ(distance1D(3, 7), 4);
}

TEST(GeometryUtilsTest, DistanceNegative) {
    EXPECT_EQ(distance1D(-5, 3), 8);
}

TEST(GeometryUtilsTest, DistanceCoincident) {
    EXPECT_EQ(distance1D(4, 4), 0);
}

TEST(GeometryUtilsTest, DistanceMixed) {
    EXPECT_DOUBLE_EQ(distance1D(2, 5.5), 3.5);
}
```

Use the following commands to build, test, and analyze the project.

## Example of running the application

![alt text](/home/ilya/programming-part-2/lab10/assets/image-1.png)


## Example of running the tests

![alt text](/home/ilya/programming-part-2/lab10/assets/image.png)


### Observations and Conclusion

This lab, while beeing noticably shorter and smaller than others, was still quite interesting. Method templates are an interesting topic, and i found myself looking up some more information on it during my work. I can totally see how it can be extremely useful in many scenarios, since it allows making methods with similar processes but different data.

---
