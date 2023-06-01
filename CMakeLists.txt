cmake_minimum_required(VERSION 3.18)

project(tals) 

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include glad/include)

add_library(glad STATIC glad/src/gl.c glad/src/egl.c)
add_library(glScreenshotHelper STATIC src/glScreenshotHelper.cpp include/glScreenshotHelper.h)

target_include_directories(glad PUBLIC include/)

target_link_libraries(glScreenshotHelper glad)

enable_testing()
add_subdirectory(tests)
