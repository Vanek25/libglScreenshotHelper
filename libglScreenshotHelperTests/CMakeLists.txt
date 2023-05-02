cmake_minimum_required(VERSION 3.18)

project(tests) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(glScreenshotHelper PUBLIC ${PROJECT_SOURCE_DIR}/libglScreenshotHelper/include)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(tests PRIVATE glScreenshotHelper cppunit)

enable_testing()

add_test(NAME tests COMMAND tests)