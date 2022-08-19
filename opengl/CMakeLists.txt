cmake_minimum_required(VERSION 3.9)
project(opengl-cmake-test)

#GLFW additions
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm)

include_directories(lib/glfw/include)
include_directories(lib/include)
include_directories(lib/glad)


add_executable(opengl-cmake-test src/main.cpp src/Shader.cpp src/Shader.h src/Camera.cpp src/Camera.h lib/src/glad.c)

target_link_libraries(opengl-cmake-test glfw glm)

