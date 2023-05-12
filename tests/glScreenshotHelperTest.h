#ifndef GL_SCREENSHOT_HELPER_TEST_H
#define GL_SCREENSHOT_HELPER_TEST_H

#include <cppunit/extensions/HelperMacros.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class ScreenshotHelperTest : public CPPUNIT_NS::TestFixture
        {
            CPPUNIT_TEST_SUITE(ScreenshotHelperTest);
                CPPUNIT_TEST(testCreateFilename);
                CPPUNIT_TEST(testFindCatalogUsbName);
                CPPUNIT_TEST(testTakeAndLoadScreenshot);
            CPPUNIT_TEST_SUITE_END();

            public:
            void setUp();
            void tearDown();

            void testCreateFilename();
            void testFindCatalogUsbName();
            void testTakeAndLoadScreenshot();

        };
    }
}

#endif