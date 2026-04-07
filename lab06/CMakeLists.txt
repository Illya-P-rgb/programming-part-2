cmake_minimum_required(VERSION 3.20)
project(document_layout LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(document_lib
    private/Document.cpp
    private/Paragraph.cpp
    private/Table.cpp
    private/Image.cpp
    private/Header.cpp
)

target_include_directories(document_lib PUBLIC public)
target_compile_features(document_lib PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(document_lib PRIVATE /W4)
else()
    target_compile_options(document_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(document
    main.cpp
)

target_link_libraries(document PRIVATE document_lib)

add_executable(document_tests
    tests/test_document.cpp
)

target_link_libraries(document_tests
    PRIVATE document_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(document_tests)