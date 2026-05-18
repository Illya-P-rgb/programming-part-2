cmake_minimum_required(VERSION 3.20)

project(lab13_sensor_processing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(public)

set(SOURCES
    private/StringUtils.cpp
    private/Record.cpp
    private/ReportBuilder.cpp
)

add_executable(main
    main.cpp
    ${SOURCES}
)

set_target_properties(main PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# IMPORTANT: disable system GTest completely
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/test_text_processing.cpp
    ${SOURCES}
)

target_link_libraries(tests
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)