cmake_minimum_required(VERSION 3.31)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracing main.cpp
        libs/stb_image_write.h
        libs/stb.h
        libs/stb_image.h)
