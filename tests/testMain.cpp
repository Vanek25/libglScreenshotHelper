#include "glScreenshotHelperTest.h"
#include "libglScreenshotHelper/glScreenshotHelper.h"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{ 
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    
    runner.addTest(registry.makeTest());
    bool wasSuccessful = runner.run("", false);
    
    return !wasSuccessful;     
}
    