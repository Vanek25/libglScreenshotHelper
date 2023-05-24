#include <dirent.h>
#include <vector>
#include <ctime>
#include <cstring>
#include <string>
#include <iostream>
#include <chrono>
#include "testCreateFileName.h"
#include <libglScreenshotHelper/glScreenshotHelper.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestCreateFileName);

        void TestCreateFileName::setUp(){}

        void TestCreateFileName::tearDown(){}

        void TestCreateFileName::test_i_tals_createFileName()
        {
            ScreenshotHelper sHelper;

            std::string fileName = std::string("screenshot_") + std::string("24-05-23") + (".jpg");
            std::string fileNameFromLib = sHelper.i_tals_createFileName("jpg").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = std::string("screenshot_") + std::string("24-05-23") + (".png");
            fileNameFromLib = sHelper.i_tals_createFileName("png").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = std::string("screenshot_") + std::string("24-05-23") + (".bmp");
            fileNameFromLib = sHelper.i_tals_createFileName("bmp").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);
        }
    }
}