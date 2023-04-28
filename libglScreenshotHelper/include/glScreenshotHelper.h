#ifndef GL_SCREENSHOT_HELPER_H
#define GL_SCREENSHOT_HELPER_H

#include <vector>
#include <string>

class ScreenshotHelper
{
    public:
        char *i_tals_createFileName(const char *type);
        std::vector<std::string> i_tals_findCatalogUsbName();
        void takeAndLoadScreenshot(const char *type, int width, int height);
};

#endif