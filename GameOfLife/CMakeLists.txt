cmake_minimum_required (VERSION 3.5)

project(GameOfLife LANGUAGES C CXX)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -lSDL2 -lGL -lSDL2_image")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable(GameOfLife ${source_files})
