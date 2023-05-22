cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../libglScreenshotHelper/include)

add_library(glScreenshotHelper_static STATIC src/glScreenshotHelper.cpp include/glScreenshotHelper.h)
add_library(glScreenshotHelper SHARED src/glScreenshotHelper.cpp)

target_include_directories(glScreenshotHelper PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(glScreenshotHelper_static)

set_target_properties(
    glScreenshotHelper_static PROPERTIES LINKER_LANGUAGE CXX
    glScreenshotHelper        PROPERTIES LINKER_LANGUAGE CXX
) 

find_package(
    glfw3 3.3 REQUIRED
    OpenGL REQUIRED
)

find_library(
    LIB_freeimage freeimage
    LIB_cppunit cppunit
)

install(FILES "${PROJECT_SOURCE_DIR}/build/libglScreenshotHelper.so" DESTINATION /usr/lib/libglScreenshotHelper)
install(TARGETS glScreenshotHelper DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES "${PROJECT_SOURCE_DIR}/include/glScreenshotHelper.h" DESTINATION /usr/local/include/libglScreenshotHelper)

#    ТЕСТЫ, но это позже     #

# include(CTest)
# enable_testing()
# add_test(NAME tals COMMAND tals)

#add_subdirectory(libglScreenshotHelperTests)
