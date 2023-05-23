#include <dirent.h>
#include <vector>
#include "testFindCatalogUsbName.h"
#include <libglScreenshotHelper/glScreenshotHelper.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestFindCatalogUsbName);

        void TestFindCatalogUsbName::setUp(){}

        void TestFindCatalogUsbName::tearDown(){}

        /*  Функция проверки пути до каталога   */
        bool TestFindCatalogUsbName::directoryExists(const char* path)
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

        /*  Функция сравнивающая названия каталогов, которые нашла функция в библиотеке, с текущими названиями каталогов    */
        void TestFindCatalogUsbName::test_i_tals_findCatalogUsbName()
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
    }
}