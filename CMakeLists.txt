cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./libglScreenshotHelper/include)

add_library(glScreenshotHelper STATIC ./libglScreenshotHelper/src/libglScreenshotHelper.a)
set_target_properties(glScreenshotHelper PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} libglScreenshotHelper/src/main.cpp) #libglScreenshotHelper/src/glScreenshotHelper.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

find_library(LIB_freeimage freeimage)

target_link_libraries(${PROJECT_NAME} freeimage glScreenshotHelper ${OPENGL_LIBRARIES} glfw)