cmake_minimum_required(VERSION 3.20)
project(lab_delivery_order LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(delivery_lib src/lib.cpp)
target_include_directories(delivery_lib PUBLIC include)
target_compile_features(delivery_lib PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(delivery_lib PRIVATE /W4)
else()
    target_compile_options(delivery_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(delivery_app assets/main.cpp)
target_link_libraries(delivery_app PRIVATE delivery_lib)

add_executable(delivery_tests
    tests/test_main.cpp
    tests/tests.cpp
)

target_link_libraries(delivery_tests
    PRIVATE delivery_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(delivery_tests)