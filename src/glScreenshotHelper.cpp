#include <GL/gl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <string>
#include <cstdint>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <FreeImage.h>
#include "glScreenshotHelper.h"

#define VNIIFTRI_DEBUG

#ifdef VNIIFTRI_DEBUG
#define D(TYPE, MESSAGE, VALUE) std::cerr<< TYPE << " I_TALS: " << MESSAGE << VALUE << std::endl
#else
#define D(TYPE, MESSAGE, VALUE)
#endif

#define DEFAULT_PATH "/home/uba/media"

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        std::string ScreenshotHelper::i_tals_createFileName(const std::string screenshotType)
        {
            std::time_t dateTimeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream dateStr;

            dateStr << std::put_time(std::localtime(&dateTimeNow), "%d-%m-%y_%T.");

            if(dateStr << "") D("[E]", "Не удалось создать название файла скриношта. Возможно проблемы со встроенным временем!", "");

            std::string fileName = std::string("screenshot_") + std::string(dateStr.str()) + std::string(screenshotType);

            return fileName;
        }

        std::vector<std::string> ScreenshotHelper::i_tals_findCatalogUsbName()
        {
            int catalogsCount = 0;
            char catalogName[255];

            std::vector<std::string> catalogNameVec;

            DIR *dirPath;
            struct dirent *entry;
            dirPath = opendir(DEFAULT_PATH);

            if (dirPath == NULL)
            {
                D("[E]", "Не удалось открыть каталог куда монируется USB накопитель! Путь указывает на несуществующий каталог: ", DEFAULT_PATH);
            }

            while ((entry = readdir(dirPath)) != NULL)
            {
                if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
                {
                    catalogsCount++;
                    strcpy(catalogName, "/");
                    strncat(catalogName, entry->d_name, 254);
                    strcat(catalogName, "/");
                    catalogName[254] = '\0';
                    catalogNameVec.push_back(catalogName);
                }
            }

            if (catalogsCount == 0)
            {
                D("[E]", "Не обнаружен каталог USB накопителя! Проверьте исправность USB накопителя.","");
            }

            if (catalogsCount > 1)
            {
                D("[I]", "Найдено более одного раздела USB накопителя.", ""); 
            }

            closedir(dirPath);
            delete[] entry;

            return catalogNameVec;
        }

        int ScreenshotHelper::i_tals_takeAndLoadScreenshot(const char *type, int width, int height)
        {
            if ((strcmp(type, "bmp")) != 0 && (strcmp(type, "jpg")) != 0 && (strcmp(type, "png")) != 0)
            {
                D("[E]", "Неверный тип скриншота: ", type);
                return -1;
            }
            
            std::vector<std::string> catalogUsbNameVec;
            std::string fileName;
            
            try
            {
                catalogUsbNameVec = i_tals_findCatalogUsbName();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return -1;
            }

            try
            {
                fileName = i_tals_createFileName(type);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return -1;
            }

            BYTE *pixels = new BYTE[3 * width * height];
            glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);

            FIBITMAP *image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
            
            if (image == NULL)
            {
                D("[E]", "Не удалось сконвертировать необработанное растровое изображение в растровое изображение!", "");
                return -1; 
            }

            char * charFileName = fileName.data();

            for(std::vector<int>::size_type i = 0; i < catalogUsbNameVec.size(); i++)
            {
                char *pathToLoadScreenshot = new char[strlen(DEFAULT_PATH) + strlen(catalogUsbNameVec[i].c_str()) + strlen(charFileName) + 1];

                strcpy(pathToLoadScreenshot, DEFAULT_PATH);
                strcat(pathToLoadScreenshot, catalogUsbNameVec[i].c_str());
                strcat(pathToLoadScreenshot, charFileName);

                try
                {
                    FreeImage_Save(FreeImage_GetFIFFromFilename(charFileName), image, pathToLoadScreenshot, 0);
                    D("[I]", "Скриншот сохранен во все доступные каталоги USB", ""); 
                }
                catch(const std::exception& e)
                {
                    if(catalogUsbNameVec.size() == 1) // если найден только один "запароленый" каталог и других нет
                    {
                        D("[E]", "Не удалось сохранить скриншот! Недостаточно прав для сохранения в каталог ", catalogUsbNameVec[i]);
                    }
                    return -1;
                }

                delete[] pathToLoadScreenshot;
            }
            
            FreeImage_Unload(image);

            delete[] pixels;

            return 0; 
        }
    }
}
