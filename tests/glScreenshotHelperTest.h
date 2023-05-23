#ifndef GL_SCREENSHOT_HELPER_TEST_H
#define GL_SCREENSHOT_HELPER_TEST_H

#include <cppunit/extensions/HelperMacros.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class ScreenshotHelperTest : public CppUnit::TestFixture
        {
            CPPUNIT_TEST_SUITE (ScreenshotHelperTest);
                CPPUNIT_TEST (test_i_tals_findCatalogUsbName);
                CPPUNIT_TEST (test_i_tals_takeAndLoadScreenshot);
            CPPUNIT_TEST_SUITE_END ();

            public:
            void setUp();
            void tearDown();

            void test_i_tals_findCatalogUsbName();
            void test_i_tals_takeAndLoadScreenshot();
            int runTests();
            int main();
        };
    }
}

#endif