cmake_minimum_required(VERSION 3.8)
project(per-pixel-shader)

set(CMAKE_CXX_STANDARD 20)

add_executable(per-pixel-shader src/main.cpp src/Demo.cpp)
target_include_directories(per-pixel-shader PUBLIC include external/PixelGameEngine)