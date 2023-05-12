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
#include "glScreenshotHelper.h"

namespace vniiftri
{
    namespace oscilloscope_gui
    {
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

            const char *type = "png";
            time_t t = time(nullptr);
            tm *dateTimeNow = localtime(&t);

            char shrtFileName[64];
            strftime(shrtFileName, sizeof(shrtFileName), "screenshot_%d-%m-%y_%X.", dateTimeNow);

            char *fileName = new char[strlen(shrtFileName) + strlen(type) + 1];

            strcpy(fileName, shrtFileName);
            strcat(fileName, type);

            CPPUNIT_ASSERT(2 == 6);
            CPPUNIT_ASSERT(sHelper.i_tals_createFileName("png") == sHelper.i_tals_createFileName("jpg"));
            //CPPUNIT_ASSERT(sHelper.i_tals_createFileName("jpg") == fileName);
            //CPPUNIT_ASSERT(sHelper.i_tals_createFileName("pss") == fileName);
            //CPPUNIT_ASSERT(sHelper.i_tals_createFileName("qads") == fileName);
        }

        void ScreenshotHelperTest::testFindCatalogUsbName()
        {
            // ScreenshotHelper sHelper;
            // std::vector<std::string> catalogNameVec;
            // catalogNameVec.push_back("aaa");
            // catalogNameVec.push_back("zxc");
            //CPPUNIT_ASSERT_EQUAL(sHelper.i_tals_findCatalogUsbName(), catalogNameVec);

        }

        void ScreenshotHelperTest::testTakeAndLoadScreenshot()
        {

        }
    }
}


