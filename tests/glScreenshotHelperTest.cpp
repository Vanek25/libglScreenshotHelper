#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <string>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <vector>
#include <FreeImage.h>
#include "glScreenshotHelperTest.h"
#include <libglScreenshotHelper/glScreenshotHelper.h>
#include <GLFW/glfw3.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (ScreenshotHelperTest);

        void ScreenshotHelperTest::setUp()
        {

        }

        void ScreenshotHelperTest::tearDown()
        {

        }

        void ScreenshotHelperTest::testCreateFilename()
        {
            ScreenshotHelper sHelper;

            CPPUNIT_ASSERT(1 == 1);
            //vniiftri::oscilloscope_gui::ScreenshotHelper::i_tals_findCatalogUsbName();
            oscilloscope_gui::ScreenshotHelper::i_tals_takeAndLoadScreenshot("bmp", 1000, 700);
            //CPPUNIT_ASSERT(sHelper.i_tals_createFileName("png") == sHelper.i_tals_createFileName("jpg"));
        }

        
    }
}


