cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_library(glScreenshotHelper_static STATIC src/glScreenshotHelper.cpp include/glScreenshotHelper.h)

find_package(
    glfw3 3.3 REQUIRED
    OpenGL REQUIRED
)

find_library(
    LIB_freeimage freeimage
    LIB_cppunit cppunits
)

enable_testing()
add_subdirectory(tests)
