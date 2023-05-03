cmake_minimum_required(VERSION 3.18)

project(tals) 

add_subdirectory(libglScreenshotHelper bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./libglScreenshotHelper/include)

add_library(glScreenshotHelper_static STATIC ./libglScreenshotHelper/src/libglScreenshotHelper.a)
#add_library(glScreenshotHelper SHARED ./libglScreenshotHelper/src/glScreenshotHelper.cpp)

target_include_directories(glScreenshotHelper PUBLIC ${PROJECT_SOURCE_DIR}/libglScreenshotHelper/include)

set_target_properties(glScreenshotHelper_static PROPERTIES LINKER_LANGUAGE CXX) 
set_target_properties(glScreenshotHelper PROPERTIES LINKER_LANGUAGE CXX) 

#add_executable(tals libglScreenshotHelper/src/glScreenshotHelper.cpp) #libglScreenshotHelperTests/glScreenshotHelperTest.cpp libglScreenshotHelperTests/testMain.cpp)

install(FILES "${PROJECT_SOURCE_DIR}/build/libglScreenshotHelper.so" DESTINATION /usr/lib/libglScreenshotHelper)
install(TARGETS glScreenshotHelper DESTINATION /usr/local/lib/libglScreenshotHelper/bin)
install(FILES "${PROJECT_SOURCE_DIR}/libglScreenshotHelper/include/glScreenshotHelper.h" DESTINATION /usr/local/include/libglScreenshotHelper)
#install(DIRECTORY "${PROJECT_SOURCE_DIR}/libglScreenshotHelper/include" DESTINATION /usr/local/lib/libglScreenshotHelper/include)


find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

find_library(LIB_freeimage freeimage)
find_library(LIB_cppunit cppunit)

#target_link_libraries(${PROJECT_NAME} freeimage glScreenshotHelper_static cppunit ${OPENGL_LIBRARIES} glfw)

# include(CTest)
# enable_testing()
# add_test(NAME tals COMMAND tals)

#add_subdirectory(libglScreenshotHelperTests)

