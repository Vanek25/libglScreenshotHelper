#include <string>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "testCreateFileName.h"
#include "../include/glScreenshotHelper.h"

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestCreateFileName);

        void TestCreateFileName::setUp(){}

        void TestCreateFileName::tearDown(){}

        void TestCreateFileName::test_i_tals_createFileName()
        {
            std::time_t t = std::time(nullptr);
            std::tm* now = std::localtime(&t);

            std::string hour, minute, second;
            
            // Добавление 0 ко времени, если число меньше 10и
            now->tm_hour < 10 ? hour = "0" + std::to_string(now->tm_hour) : hour = std::to_string(now->tm_hour);
            now->tm_min < 10 ? minute = "0" + std::to_string(now->tm_min) : minute = std::to_string(now->tm_min);
            now->tm_sec < 10 ? second = "0" + std::to_string(now->tm_sec) : second = std::to_string(now->tm_sec);

            /*  Сравнение названий файла со временем  */
            int delaySec = 3;
            
            std::string fileName = std::string("screenshot_13-06-23_") + hour + ":" + minute + ":" + second + (".jpg");

            CPPUNIT_ASSERT_EQUAL(fileName, ScreenshotHelper::i_tals_createFileName("jpg"));

            sleep(delaySec);

            now->tm_sec += delaySec;
            now->tm_sec < 10 ? second = "0" + std::to_string(now->tm_sec) : second = std::to_string(now->tm_sec);

            fileName = std::string("screenshot_13-06-23_") + hour + ":" + minute + ":" + second + (".jpg");

            CPPUNIT_ASSERT_EQUAL(fileName, ScreenshotHelper::i_tals_createFileName("jpg"));

            /*   Сравнение названий файла без времени   */
            fileName = "screenshot_13-06-23.jpg";
            std::string fileNameFromLib = ScreenshotHelper::i_tals_createFileName("jpg").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = "screenshot_13-06-23.png";
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("png").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);

            fileName = "screenshot_13-06-23.bmp";
            fileNameFromLib = ScreenshotHelper::i_tals_createFileName("bmp").erase(19, 9);
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);
        }
    }
}