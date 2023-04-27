#ifndef GL_SCREENSHOT_HELPER_TEST_H
#define GL_SCREENSHOT_HELPER_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../include/glScreenshotHelper.h"

class ScreenshotHelperTest : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(ScreenshotHelperTest);
        CPPUNIT_TEST(testCreateFilename);
        CPPUNIT_TEST(testFindCatalogUsbName);
        CPPUNIT_TEST(testTakeAndLoadScreenshot);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testCreateFilename();
        void testFindCatalogUsbName();
        void testTakeAndLoadScreenshot();
    
    
};

#endif