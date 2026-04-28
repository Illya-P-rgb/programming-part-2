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