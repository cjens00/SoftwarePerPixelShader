cmake_minimum_required(VERSION 3.8)
project(pge_fun)

set(CMAKE_CXX_STANDARD 20)

add_executable(pge_fun src/main.cpp src/Demo.cpp)
target_include_directories(pge_fun PUBLIC include external/PixelGameEngine)