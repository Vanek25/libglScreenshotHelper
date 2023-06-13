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
#include <unistd.h>
#include <filesystem>
#include <FreeImage.h>
#include "glScreenshotHelper.h"
#include "glad/gl.h"

#ifdef VNIIFTRI_DEBUG
#define D(TYPE, MESSAGE, VALUE) std::cerr<< TYPE << " I_TALS: " << MESSAGE << VALUE << std::endl
#else
#define D(TYPE, MESSAGE, VALUE)
#endif

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        bool ScreenshotHelper::i_tals_isEnoughSpace(const char *pathToCatalog, const char *screenshotType)
        {
            std::string fullPath = DEFAULT_PATH;
            fullPath.append(pathToCatalog);

            std::filesystem::space_info tmp = std::filesystem::space(fullPath);
            
            if(tmp.free < 15000000 && screenshotType == "bmp") // если меньше 15 Мбайт на флешке
                return false; 

            if(tmp.free < 1000000 && screenshotType == "png") // если меньше 1 Мбайт на флешке
                return false;
            
            if(tmp.free < 1000000 && screenshotType == "jpg")
                return false;

            return true;
        }

        std::vector<std::string> ScreenshotHelper::i_tals_checkFreeSpace(std::vector<std::string> catalogUsbNames, const char *screenshotType)
        {
            std::vector<std::string> availableCatalogs;
            for(int i = 0; i < catalogUsbNames.size(); i++)
            {
                if(i_tals_isEnoughSpace(catalogUsbNames[i].c_str(), screenshotType) == true) // вызов функции, проверяющией свободное место в каталоге(ах) накопителя
                {
                    availableCatalogs.push_back(catalogUsbNames[i]);
                }
            }

            return availableCatalogs;
        }

        std::string ScreenshotHelper::i_tals_createFileName(const std::string screenshotType)
        {
            std::time_t dateTimeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream dateStr;

            dateStr << std::put_time(std::localtime(&dateTimeNow), "%d-%m-%y_%T.");

            if(dateStr.str() == "") D("[E]", "Не удалось создать название файла скриношта. Возможно проблемы со встроенным временем!", "");

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
                return catalogNameVec;
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
                catalogUsbNameVec = i_tals_checkFreeSpace(i_tals_findCatalogUsbName(), type); // вызов функции на проверку 
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

            if(catalogUsbNameVec.empty())
            {
                D("[E]", "Недостаточно места для сохранения скриншота! Вставьте другой USB-накопитель.", "");
                return -1;
            }
               
            uint8_t* pixels = new uint8_t[width * height * 3];
            glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);
            
            FIBITMAP *image; 

            try
            {
                image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
            }
            catch(const std::exception& e)
            {
                D("[E]", "Не удалось сконвертировать необработанное растровое изображение в растровое изображение!", "");
                return -1;
            }

            char *charFileName = fileName.data();
            int countCtlgNotEnoghSpace = 0;

            for(std::vector<int>::size_type i = 0; i < catalogUsbNameVec.size(); i++)
            {
                char *pathToLoadScreenshot = new char[strlen(DEFAULT_PATH) + strlen(catalogUsbNameVec[i].c_str()) + strlen(charFileName) + 1];

                strcpy(pathToLoadScreenshot, DEFAULT_PATH);
                strcat(pathToLoadScreenshot, catalogUsbNameVec[i].c_str());
                strcat(pathToLoadScreenshot, charFileName);

                try
                {
                    FreeImage_Save(FreeImage_GetFIFFromFilename(charFileName), image, pathToLoadScreenshot, 0);
                    D("[I]", "Скриншот сохранен в каталог: ", catalogUsbNameVec[i]); 
                }
                catch(const std::exception& e)
                {
                    if(catalogUsbNameVec.size() == 1) // если найден только один "запароленный" каталог и других нет
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
