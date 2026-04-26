cmake_minimum_required(VERSION 3.20)
project(lab07 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(public)

set(SOURCES
    private/CityObject.cpp
    private/Building.cpp
    private/ResidentialBuilding.cpp
    private/IndustrialBuilding.cpp
)

add_executable(main
    main.cpp
    ${SOURCES}
)