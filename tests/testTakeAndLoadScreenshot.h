#ifndef TEST_TAKE_AND_LOAD_SCREENSHOT_H
#define TEST_TAKE_AND_LOAD_SCREENSHOT_H

#include <cppunit/extensions/HelperMacros.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class TakeAndLoadScreenshotTest : public CppUnit::TestFixture
        {
            CPPUNIT_TEST_SUITE (TakeAndLoadScreenshotTest);
                CPPUNIT_TEST (test_i_tals_takeAndLoadScreenshot);
            CPPUNIT_TEST_SUITE_END ();

            public:
            void setUp();
            void tearDown();

            void test_i_tals_takeAndLoadScreenshot();
        };
    }
}

#endif