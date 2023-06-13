#include <vector>
#include "testFindCatalogUsbName.h"
#include "../include/glScreenshotHelper.h"

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestFindCatalogUsbName);

        void TestFindCatalogUsbName::setUp(){}

        void TestFindCatalogUsbName::tearDown(){}

        void TestFindCatalogUsbName::test_i_tals_findCatalogUsbName()
        {
            std::vector<std::string> vecPathsToDirs;
            std::vector<std::string> vecPathToDirsFromLib = ScreenshotHelper::i_tals_findCatalogUsbName(); 
            
            vecPathsToDirs.push_back("/papka/");

            bool isSimilar;

            vecPathsToDirs == vecPathToDirsFromLib ? isSimilar = true : isSimilar = false;

            CPPUNIT_ASSERT(isSimilar);
        }
    }
}