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