cmake_minimum_required(VERSION 3.18)

project(tals LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/glScreenshotHelper.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

find_library(LIB_freeimage freeimage)

target_link_libraries(${PROJECT_NAME} freeimage ${OPENGL_LIBRARIES} glfw)