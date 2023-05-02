cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./libglScreenshotHelper/include)

add_library(glScreenshotHelper STATIC ./libglScreenshotHelper/src/libglScreenshotHelper.a)
target_include_directories(glScreenshotHelper PUBLIC ${PROJECT_SOURCE_DIR}/libglScreenshotHelper/include)

set_target_properties(glScreenshotHelper PROPERTIES LINKER_LANGUAGE CXX) 

add_executable(tals libglScreenshotHelper/src/main.cpp libglScreenshotHelper/src/glScreenshotHelper.cpp libglScreenshotHelperTests/glScreenshotHelperTest.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

find_library(LIB_freeimage freeimage)
find_library(LIB_cppunit cppunit)

target_link_libraries(${PROJECT_NAME} freeimage  glScreenshotHelper cppunit ${OPENGL_LIBRARIES} glfw)
include(CTest) # We include CTest which is part of CMake

enable_testing()

add_test(NAME tals COMMAND tals)

add_subdirectory(libglScreenshotHelperTests)
add_subdirectory(libglScreenshotHelper)

