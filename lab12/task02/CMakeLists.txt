cmake_minimum_required(VERSION 3.20)

project(lab12_task02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(public)

add_executable(main
    main.cpp
    private/DomainTypes.cpp
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_sample
    tests/test.cpp
    private/DomainTypes.cpp
)

target_link_libraries(test_sample
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_sample)