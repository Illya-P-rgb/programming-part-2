cmake_minimum_required(VERSION 3.20)

project(lab12_task09 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(public)

set(SOURCES
    private/DomainTypes.cpp
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

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_shared_ptr
    tests/test.cpp
    ${SOURCES}
)

target_link_libraries(test_shared_ptr
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_shared_ptr)