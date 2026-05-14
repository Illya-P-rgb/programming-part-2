cmake_minimum_required(VERSION 3.20)

project(lab12_task10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(public)

set(SOURCES
    private/DomainTypes.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")

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

add_executable(test_weak_ptr
    tests/test.cpp
    ${SOURCES}
)

target_link_libraries(test_weak_ptr
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_weak_ptr)