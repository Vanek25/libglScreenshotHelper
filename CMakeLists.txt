cmake_minimum_required(VERSION 3.18)

project(tals) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../libglScreenshotHelper/include)

add_library(glScreenshotHelper_static STATIC src/glScreenshotHelper.cpp include/glScreenshotHelper.h)
add_library(glScreenshotHelper SHARED src/glScreenshotHelper.cpp)

add_executable(i_tals_takeAndLoadScreenshot_test tests/testMain.cpp tests/testTakeAndLoadScreenshot.cpp include/glScreenshotHelper.h)
add_executable(i_tals_findCatalogUsbName_test tests/testMain.cpp tests/testFindCatalogUsbName.cpp include/glScreenshotHelper.h)
add_executable(i_tals_create_file_name_test tests/testMain.cpp tests/testCreateFileName.cpp include/glScreenshotHelper.h)

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

target_link_libraries(i_tals_takeAndLoadScreenshot_test cppunit glScreenshotHelper freeimage GL)
target_link_libraries(i_tals_findCatalogUsbName_test cppunit glScreenshotHelper freeimage GL)
target_link_libraries(i_tals_create_file_name_test cppunit glScreenshotHelper freeimage GL)

install(FILES "${PROJECT_SOURCE_DIR}/build/libglScreenshotHelper.so" DESTINATION /usr/lib/libglScreenshotHelper)
install(TARGETS glScreenshotHelper DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES "${PROJECT_SOURCE_DIR}/include/glScreenshotHelper.h" DESTINATION /usr/local/include/libglScreenshotHelper)

#   ТЕСТЫ   #

option (UNIT_TEST "Build unit tests" ON)
if (UNIT_TEST)
   enable_testing ()
   add_test(NAME i_tals_takeAndLoadScreenshot_test COMMAND i_tals_takeAndLoadScreenshot_test)
   add_test(NAME i_tals_findCatalogUsbName_test COMMAND i_tals_findCatalogUsbName_test)
   add_test(NAME i_tals_create_file_name_test COMMAND i_tals_create_file_name_test)
endif()
