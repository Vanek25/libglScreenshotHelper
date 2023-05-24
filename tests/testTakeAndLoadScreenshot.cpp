#include "testTakeAndLoadScreenshot.h"
#include <libglScreenshotHelper/glScreenshotHelper.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TakeAndLoadScreenshotTest);

        void TakeAndLoadScreenshotTest::setUp(){}

        void TakeAndLoadScreenshotTest::tearDown(){}

        void TakeAndLoadScreenshotTest::test_i_tals_takeAndLoadScreenshot()
        {
            /*  Проверка на создание скриншотов с разным типом и размером окна  */
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("bmp", 1000, 700) == 0);
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("png", 100, 60) == 0);
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("jpg", 700, 600) == 0);
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("bmp", 450, 200) == 0);
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("png", 633, 322) == 0);
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("jpg", 800, 600) == 0);

            /*  Проверка на создание скриншотов с неверным типом    */
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("фывафвыафвыаа", 800, 600) == -1); // -1 возвращает функция в случае ошибки
            CPPUNIT_ASSERT(ScreenshotHelper::i_tals_takeAndLoadScreenshot("jppg", 1200, 1080) == -1);
        }
    }
}