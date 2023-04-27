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
#include "../include/glScreenshotHelper.h"

class ScreenshotHelperTest : public CppUnit::TestFixture
{
    public:
        virtual void runTest() override
        {
            ScreenshotHelper sHelper;

            time_t t = time(nullptr);
            tm *dateTimeNow = localtime(&t);

            char shrtFileName[64];
            strftime(shrtFileName, sizeof(shrtFileName), "screenshot_%d-%m-%y_%X.", dateTimeNow);

            char *fileName = new char[strlen(shrtFileName) + strlen(type) + 1];

            strcpy(fileName, shrtFileName);
            strcat(fileName, type);

            // Ask using CPPUnit_assert
            CPPUNIT_ASSERT(3 == sHelper.i_tals_createFileName("png"));
            CPPUNIT_ASSERT(1 == sHelper.sub(2, 1));
        }
};