#ifndef TEST_FIND_CATALOG_USB_NAME_H
#define TEST_FIND_CATALOG_USB_NAME_H

#include <cppunit/extensions/HelperMacros.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class TestFindCatalogUsbName : public CppUnit::TestFixture
        {
            CPPUNIT_TEST_SUITE (TestFindCatalogUsbName);
                CPPUNIT_TEST (test_i_tals_findCatalogUsbName);
            CPPUNIT_TEST_SUITE_END ();

            public:
            void setUp();
            void tearDown();

            void test_i_tals_findCatalogUsbName();
            bool directoryExists(const char* path);
        };
    }
}

#endif