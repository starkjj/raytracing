cmake_minimum_required(VERSION 3.31)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs libs/glm src)

add_executable(raytracing src/main.cpp)
