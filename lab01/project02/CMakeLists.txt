cmake_minimum_required(VERSION 3.20)
project(project02 LANGUAGES CXX)

add_library(math_utils src/math_utils.cpp)
target_include_directories(math_utils PUBLIC include)
target_compile_features(math_utils PUBLIC cxx_std_20)

add_executable(app app/main.cpp)
target_link_libraries(app PRIVATE math_utils)
