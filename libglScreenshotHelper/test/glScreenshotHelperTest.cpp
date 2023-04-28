#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
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
#include "../include/glScreenshotHelper.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ScreenshotHelperTest);

void ScreenshotHelperTest::setUp()
{

}

void ScreenshotHelperTest::tearDown()
{

}

void ScreenshotHelperTest::testCreateFilename()
{
    ScreenshotHelper sHelper;
    CPPUNIT_ASSERT(sHelper.i_tals_createFileName("png"));
    CPPUNIT_ASSERT(sHelper.i_tals_createFileName("bmp"));
    CPPUNIT_ASSERT(sHelper.i_tals_createFileName("jpg"));
    CPPUNIT_ASSERT(sHelper.i_tals_createFileName("pss"));
    CPPUNIT_ASSERT(sHelper.i_tals_createFileName("qads"));
}

void ScreenshotHelperTest::testFindCatalogUsbName()
{
    ScreenshotHelper sHelper;

}

void ScreenshotHelperTest::testTakeAndLoadScreenshot()
{
    
}