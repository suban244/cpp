cmake_minimum_required (VERSION 3.5)

project(Minesweeper LANGUAGES C CXX)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -std=c++14 -lSDL2 -lGL -lSDL2_image -lSDL2_ttf")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable(Minesweeper ${source_files})
