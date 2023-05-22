cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../libglScreenshotHelper/include)

add_library(glScreenshotHelper_static STATIC src/glScreenshotHelper.cpp include/glScreenshotHelper.h)
add_library(glScreenshotHelper SHARED src/glScreenshotHelper.cpp)

add_executable(glsh_test tests/testMain.cpp tests/glScreenshotHelperTest.cpp)

target_include_directories(glScreenshotHelper PUBLIC ${PROJECT_SOURCE_DIR}/include)

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

target_link_libraries(glsh_test ${OPENGL_LIBRARY} glfw ${OPENGL_LIBRARY} glfw3 cppunit glScreenshotHelper freeimage GL GLU glut ${OPENGL_LIBRARIES})

install(FILES "${PROJECT_SOURCE_DIR}/build/libglScreenshotHelper.so" DESTINATION /usr/lib/libglScreenshotHelper)
install(TARGETS glScreenshotHelper DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES "${PROJECT_SOURCE_DIR}/include/glScreenshotHelper.h" DESTINATION /usr/local/include/libglScreenshotHelper)

#   ТЕСТЫ   #

option (UNIT_TEST "Build unit tests" ON)
if (UNIT_TEST)
   enable_testing ()
   add_test(NAME glsh_test COMMAND glsh_test)
else()
   message("Skip unit tests...")
endif()
