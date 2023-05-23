#ifndef TEST_CREATE_FILE_NAME_H
#define TEST_CREATE_FILE_NAME_H

#include <cppunit/extensions/HelperMacros.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class TestCreateFileName : public CppUnit::TestFixture
        {
            CPPUNIT_TEST_SUITE (TestCreateFileName);
                CPPUNIT_TEST (test_i_tals_createFileName);
            CPPUNIT_TEST_SUITE_END ();

            public:
            void setUp();
            void tearDown();

            void test_i_tals_createFileName();
        };
    }
}

#endif