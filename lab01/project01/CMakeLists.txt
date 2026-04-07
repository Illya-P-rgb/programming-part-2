cmake_minimum_required(VERSION 3.20)
project(project01 LANGUAGES CXX)

add_executable(project01 main.cpp)

target_compile_features(project01 PRIVATE cxx_std_20)
if(MSVC)
target_compile_options(project01 PRIVATE /W4)
else()
target_compile_options(project01 PRIVATE -Wall -Wextra -Wpedantic)
endif()
