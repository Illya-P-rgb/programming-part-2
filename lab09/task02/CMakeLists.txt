cmake_minimum_required(VERSION 3.20)
project(task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(public)

set(SOURCES
    private/Appliance.cpp
    private/Heater.cpp
    private/Cooler.cpp
    private/Humidifier.cpp
    private/ClimateSystem.cpp
)

add_executable(main
    main.cpp
    ${SOURCES}
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(test_basic
    tests/test_basic.cpp
    ${SOURCES}
)

target_link_libraries(test_basic
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_basic)