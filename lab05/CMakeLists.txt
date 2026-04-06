cmake_minimum_required(VERSION 3.20)
project(online_store_platform LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(store_lib
    private/Product.cpp
    private/SupportAgent.cpp
    private/Customer.cpp
    private/Order.cpp
    private/Store.cpp
)

target_include_directories(store_lib PUBLIC public)

target_compile_features(store_lib PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(store_lib PRIVATE /W4)
else()
    target_compile_options(store_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(store main.cpp)

target_link_libraries(store PRIVATE store_lib)

add_executable(store_tests
    tests/test_main.cpp
    tests/test_product.cpp
    tests/test_order.cpp
    tests/test_store.cpp
)

target_link_libraries(store_tests
    PRIVATE store_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(store_tests)