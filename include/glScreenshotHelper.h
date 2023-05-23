#ifndef GL_SCREENSHOT_HELPER_H
#define GL_SCREENSHOT_HELPER_H

#include <vector>
#include <string>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        class ScreenshotHelper
        {
            public:
                static char *i_tals_createFileName(const char *type);
                static std::vector<std::string> i_tals_findCatalogUsbName();
                static int i_tals_takeAndLoadScreenshot(const char *type, int width, int height);
        };
    }
}

#endif