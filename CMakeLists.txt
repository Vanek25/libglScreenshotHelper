cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(tests)

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

target_link_libraries(glsh_test glScreenshotHelper cppunit freeimage ${OPENGL_LIBRARIES} glfw)

install(FILES "${PROJECT_SOURCE_DIR}/build/libglScreenshotHelper.so" DESTINATION /usr/lib/libglScreenshotHelper)
install(TARGETS glScreenshotHelper DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES "${PROJECT_SOURCE_DIR}/include/glScreenshotHelper.h" DESTINATION /usr/local/include/libglScreenshotHelper)

#   ТЕСТЫ   #



option (UNIT_TEST "Build unit tests" ON)
if (UNIT_TEST)
   enable_testing ()
   add_test(NAME glsh_test COMMAND glsh_test)
   #set_tests_properties(glsh_test PROPERTIES PASS_REGULAR_EXPRESSION "TEST PASSED;Pass")
else()
   message("Skip unit tests...")
endif()
