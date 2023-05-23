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

        /*  Функция проверки пути до каталога   */
        bool directoryExists(const char* path)
        {
            if (path == NULL) return false;

            DIR *pathToDir;
            bool dirExists = false;

            pathToDir = opendir(path);

            if (pathToDir != NULL)
            {
                dirExists = true;    
                (void)closedir(pathToDir);
            }

            return dirExists;
        }

        void ScreenshotHelperTest::test_i_tals_findCatalogUsbName()
        {
            ScreenshotHelper sHelper;
            
            std::vector<std::string> pathsToDirs;
            std::vector<std::string> dirsName = sHelper.i_tals_findCatalogUsbName(); 
            
            for(int i = 0; i < sizeof(dirsName); i++)
            {
                if(!dirsName.empty())
                {
                    std::string s;
                    s.append("/home/neon/media").append(dirsName[i]);
                    pathsToDirs.push_back(s);
                    CPPUNIT_ASSERT(directoryExists(pathsToDirs[i].c_str()));
                }
                else
                {
                    CPPUNIT_ASSERT(directoryExists(NULL));
                }
            } 
        }

        void ScreenshotHelperTest::test_i_tals_takeAndLoadScreenshot()
        {
            ScreenshotHelper sHelper;

            /*  Проверка на создание скриншотов с разным типом и размером окна  */
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("bmp", 1000, 700) == 0);
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("png", 100, 60) == 0);
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("jpg", 700, 600) == 0);
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("bmp", 450, 200) == 0);
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("png", 633, 322) == 0);
            CPPUNIT_ASSERT(sHelper.i_tals_takeAndLoadScreenshot("jpg", 800, 600) == 0);
        }
    }
}


