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

        void TestFindCatalogUsbName::test_i_tals_findCatalogUsbName()
        {
            ScreenshotHelper sHelper;
            
            std::vector<std::string> vecPathsToDirs;
            std::vector<std::string> vecPathToDirsFromLib = sHelper.i_tals_findCatalogUsbName(); 
            
            vecPathsToDirs.push_back("/f1/");
            vecPathsToDirs.push_back("/f2/");
            vecPathsToDirs.push_back("/as/");
  
            bool isSimilar;

            vecPathsToDirs == vecPathToDirsFromLib ? isSimilar = true : isSimilar = false;

            CPPUNIT_ASSERT(isSimilar);
        }
    }
}