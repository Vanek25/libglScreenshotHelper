#ifndef GL_SCREENSHOT_HELPER_H
#define GL_SCREENSHOT_HELPER_H

#include <vector>
#include <string>

class ScreenshotHelper
{
    public:
        static char *i_tals_createFileName(const char *type);
        static std::vector<std::string> i_tals_findCatalogUsbName();
        static void takeAndLoadScreenshot(const char *type, int width, int height);
};

#endif