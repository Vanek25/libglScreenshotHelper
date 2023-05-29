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
            int delaySec = 3;
            std::time_t t = std::time(nullptr);
            std::tm* now = std::localtime(&t);
            std::string fileName = std::string("screenshot_29-05-23_") + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec) + (".jpg");

            CPPUNIT_ASSERT_EQUAL(fileName, ScreenshotHelper::i_tals_createFileName("jpg"));

            sleep(delaySec);
            fileName = std::string("screenshot_29-05-23_") + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec + delaySec) + (".jpg");

            CPPUNIT_ASSERT_EQUAL(fileName, ScreenshotHelper::i_tals_createFileName("jpg"));

            /*   Сравнение названий файла без времени   */
            fileName = "screenshot_29-05-23.jpg";
            std::string fileNameFromLib = ScreenshotHelper::i_tals_createFileName("jpg").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = "screenshot_29-05-23.png";
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("png").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = "screenshot_29-05-23.bmp";
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("bmp").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);
        }
    }
}