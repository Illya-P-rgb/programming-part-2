cmake_minimum_required(VERSION 3.10)
project(variant15 LANGUAGES CXX)

find_package(GTest REQUIRED)
find_package(fmt CONFIG REQUIRED)
include(GoogleTest)

add_executable(variant15
    app/main.cpp
    lib/shopping_list.cpp
)
target_include_directories(variant15 PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(variant15 PRIVATE fmt::fmt)

add_executable(my_tests
    tests/test_shopping_list.cpp
    lib/shopping_list.cpp
)
target_include_directories(my_tests PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(my_tests GTest::gtest_main)
gtest_discover_tests(my_tests)