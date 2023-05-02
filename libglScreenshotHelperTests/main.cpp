#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "glScreenshotHelperTest.h"

int main()
{
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;

    runner.addTest( suite );
    runner.setOutputter( new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

    bool wasSucessful = runner.run();

    return wasSucessful ? 0 : 1;
}
