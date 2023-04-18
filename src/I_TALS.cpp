#define _DEFAULT_SOURCE

#include "I_TALS.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <string>
#include <ctime>
#include "FreeImage.h"

#define DEFAULT_PATH "/home/ivan/media/"

char *i_tals_createFilename(char *type)
{       
    time_t t = time(nullptr);
    tm *now = localtime(&t);
 
    char filename[64];
    strftime(filename, sizeof(filename), "screenshot_%d-%m-%y_%X.", now);
    
    char *buffer = new char[std::strlen(filename)+std::strlen(type)+1];
    
    strcpy(buffer, filename);
    strcat(buffer, type);
    
    return buffer;
}

char *i_tals_findCatalogUsbName()
{
    int catalogsCount = 0;
    char catalogName[255];

    DIR *dirPath;
    struct dirent *entry;
    dirPath = opendir(DEFAULT_PATH);

    while ((entry = readdir (dirPath)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
        {
            catalogsCount++;
            strncpy(catalogName, entry->d_name, 254);
            catalogName[254] = '\0';
            printf("%s\n", catalogName);
        }      
    }

    closedir(dirPath);

    char *catalogUsb = new char[std::strlen(catalogName)];
    
    strcpy(catalogUsb, catalogName);
    strcat(catalogUsb, "/");

    catalogsCount != 0 ? printf("\nThere %d directory in the current directory.\n", catalogsCount) :  printf("\nUSB not found!\nEnter USB and try again\n");

    return catalogUsb;
}

void i_tals_takeAndLoadScreenshot(char *type, int width, int height)
{
    BYTE *pixels = new BYTE[3 * width * height];
    glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);

    FIBITMAP *image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);

    char *pathToLoadScreenshot = new char[std::strlen(DEFAULT_PATH)+std::strlen(i_tals_findCatalogUsbName())+std::strlen(i_tals_createFilename(type))];

    strcpy(pathToLoadScreenshot, DEFAULT_PATH);
    strcat(pathToLoadScreenshot, i_tals_findCatalogUsbName());
    strcat(pathToLoadScreenshot, i_tals_createFilename(type));

    printf(pathToLoadScreenshot);
    printf("\n");

    if(type == "bmp") FreeImage_Save(FIF_BMP, image, pathToLoadScreenshot, 0);
    else if(type == "jpg") FreeImage_Save(FIF_JPEG, image, pathToLoadScreenshot, 0);
    else if(type == "png") FreeImage_Save(FIF_PNG, image, pathToLoadScreenshot, 0);
    
    FreeImage_Unload(image);

    delete[] pixels;
}
