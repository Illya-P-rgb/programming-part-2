cmake_minimum_required(VERSION 3.20)
project(broken_version LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(public)

set(SOURCES
    private/Device.cpp
    private/InputDevice.cpp
    private/OutputDevice.cpp
    private/TouchDisplay.cpp
)

add_executable(main
    main.cpp
    ${SOURCES}
)