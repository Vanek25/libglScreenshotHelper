#include <string>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "testCreateFileName.h"
#include "glScreenshotHelper.h"

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestCreateFileName);

        void TestCreateFileName::setUp(){}

        void TestCreateFileName::tearDown(){}

        void TestCreateFileName::test_i_tals_createFileName()
        {
            /*  Сравнение названий файла со временем  */
            std::chrono::seconds seconds(65);
            std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(seconds);
            
            int delay = 2;
            std::string testTime = ScreenshotHelper::i_tals_createFileName("jpg");

            CPPUNIT_ASSERT_EQUAL(testTime, ScreenshotHelper::i_tals_createFileName("jpg"));

            /*   Сравнение названий файла без времени   */
            std::string fileName = std::string("screenshot_") + std::string("24-05-23") + (".jpg");
            std::string fileNameFromLib = ScreenshotHelper::i_tals_createFileName("jpg").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = std::string("screenshot_") + std::string("24-05-23") + (".png");
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("png").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = std::string("screenshot_") + std::string("24-05-23") + (".bmp");
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("bmp").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);
        }
    }
}