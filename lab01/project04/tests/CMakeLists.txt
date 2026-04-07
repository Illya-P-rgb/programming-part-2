add_executable(math_utils_tests test_math_utils.cpp)
target_link_libraries(math_utils_tests PRIVATE math_utils GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(math_utils_tests)
