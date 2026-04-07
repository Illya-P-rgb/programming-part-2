find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(my_tests test_main.cpp other_tests.cpp)
target_link_libraries(my_tests GTest::gtest_main)

gtest_discover_tests(my_tests)