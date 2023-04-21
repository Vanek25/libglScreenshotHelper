#include <GLFW/glfw3.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <string>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <FreeImage.h>

#define VNIIFTRI_DEBUG true
#define DEFAULT_PATH "/home/neon/ds"  

static char *i_tals_createFileName(const char *type)
{
    time_t t = time(nullptr);
    tm *dateTimeNow = localtime(&t);

    char shrtFileName[64];
    strftime(shrtFileName, sizeof(shrtFileName), "screenshot_%d-%m-%y_%X.", dateTimeNow);

    char *fileName = new char[strlen(shrtFileName) + strlen(type) + 1];

    strcpy(fileName, shrtFileName);
    strcat(fileName, type);

    return fileName;
}

static char *i_tals_findCatalogUsbName()
{
    int catalogsCount = 0;
    char catalogName[255];

    DIR *dirPath;
    struct dirent *entry;
    dirPath = opendir(DEFAULT_PATH);

    if (dirPath == NULL)
    {
        if(VNIIFTRI_DEBUG)std::cerr << "[E] Не удалось открыть каталог [ " << DEFAULT_PATH << " ]!" << std::endl;
        return nullptr;
    }

    while ((entry = readdir(dirPath)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
        {
            catalogsCount++;
            strncpy(catalogName, entry->d_name, 254);
            catalogName[254] = '\0';
        }
    }

    if(catalogsCount == 0)
    {
        if(VNIIFTRI_DEBUG)std::cerr << "[E] Не обнаружен каталог USB накопителя! Каталог [ " << DEFAULT_PATH << " ] пуст!" << std::endl;
        return nullptr;
    }

    if(catalogsCount > 1)
    {
        if(VNIIFTRI_DEBUG)std::cout << "Найдено более одного раздела USB накопителя. Скриншот будет помещен в каталог [ " << catalogName << " ] " << std::endl;
    }

    closedir(dirPath);

    char *catalogUsb = new char[std::strlen(catalogName) + 1];

    strcpy(catalogUsb, "/");
    strcat(catalogUsb, catalogName);
    strcat(catalogUsb, "/");

    delete[] entry;

    return catalogUsb;
}

static void takeAndLoadScreenshot(const char *type, int width, int height)
{
    if ((strcmp(type, "bmp")) != 0 && (strcmp(type, "jpg")) != 0 && (strcmp(type, "png")) != 0)
    {
        if(VNIIFTRI_DEBUG)std::cerr << "[E] Тип [ " << type << " ] не может быть использован!" << std::endl;
        return throw;
    }

    char *catalogUsbName = i_tals_findCatalogUsbName();
    char *fileName = i_tals_createFileName(type);

    if(catalogUsbName == NULL || fileName == NULL)
    {
        return throw;
    }

    BYTE *pixels = new BYTE[3 * width * height];
    glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);

    FIBITMAP *image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
    if(image == NULL)
    {
        if(VNIIFTRI_DEBUG)std::cerr << "[E] Не удалось сконвертировать необработанное растровое изображение в растровое изображение!" << std::endl;
        return throw;
    }

    char *pathToLoadScreenshot = new char[strlen(DEFAULT_PATH) + strlen(catalogUsbName) + strlen(fileName)];

    strcpy(pathToLoadScreenshot, DEFAULT_PATH);
    strcat(pathToLoadScreenshot, catalogUsbName);
    strcat(pathToLoadScreenshot, fileName);

    if(!FreeImage_Save(FreeImage_GetFIFFromFilename(fileName), image, pathToLoadScreenshot, 0))
    {
        if(VNIIFTRI_DEBUG)std::cerr << "[E] Не удалось сохранить скриншот. Тип файла "<< fileName <<" [ "<< FreeImage_GetFIFFromFilename(fileName) << " ] не определен!" << std::endl;
        return throw;
    }

    FreeImage_Save(FreeImage_GetFIFFromFilename(fileName), image, pathToLoadScreenshot, 0);
    FreeImage_Unload(image);

    delete[] catalogUsbName;
    delete[] fileName;
    delete[] pixels;
    delete[] pathToLoadScreenshot;
}


void drawQuad(const char *typeScreenshot, int width, int height)
{
    GLFWwindow *window;
    
    if (!glfwInit())
        return;

    window = glfwCreateWindow(width, height, "sss", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.3f, 0.1f, 0.6f);

        float lowNumer = 0.1f;
        float highNumber = 1.0f;

        srand(time(NULL));

        float rndNumber = lowNumer + static_cast<float>(rand()) * static_cast<float>(highNumber - lowNumer) / RAND_MAX;

        glBegin(GL_QUADS);
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(-0.9f, 0.8f); // top left
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(-0.5f, 0.8f); // top right 
            glColor3f(rndNumber, 0.1f, 0.6f);
            glVertex2f(-0.5f, 0.2f); // bottom right
            glColor3f(0.9f, rndNumber, rndNumber);
            glVertex2f(-0.9f, 0.2f); // bottom left
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(-0.9f, -0.2f); // top left
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(-0.5f, -0.2f); // top right 
            glColor3f(rndNumber, 0.1f, 0.6f);
            glVertex2f(-0.5f, -0.8f); // bottom right
            glColor3f(0.9f, rndNumber, rndNumber);
            glVertex2f(-0.9f, -0.8f); // bottom left
        glEnd();
        
        glBegin(GL_QUADS);
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(0.5f, 0.8f); // top left
            glColor3f(rndNumber, 0.1f, rndNumber);
            glVertex2f(0.9f, 0.8f); // top right 
            glColor3f(rndNumber, rndNumber, 0.1f);
            glVertex2f(0.9f, 0.2f); // bottom right
            glColor3f(rndNumber, rndNumber, rndNumber);
            glVertex2f(0.5f, 0.2f); // bottom left
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.1f, rndNumber, rndNumber);
            glVertex2f(0.5f, -0.2f); // top left
            glColor3f(rndNumber, rndNumber, rndNumber);
            glVertex2f(0.9f, -0.2f); // top right 
            glColor3f(0.9f, rndNumber, rndNumber);
            glVertex2f(0.9f, -0.8f); // bottom right
            glColor3f(rndNumber, 0.5f, rndNumber);
            glVertex2f(0.5f, -0.8f); // bottom left
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.7f, 0.7f, rndNumber);
            glVertex2f(-0.4f, 0.0f);
            glColor3f(0.5f, 0.5f, rndNumber);
            glVertex2f(0.0f, 0.7f);
            glColor3f(0.3f, 0.3f, rndNumber);
            glVertex2f(0.4f, 0.0f);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.7f, 0.7f, rndNumber);
            glVertex2f(-0.4f, 0.0f);
            glColor3f(0.5f, 0.5f, rndNumber);
            glVertex2f(0.0f, -0.7f);
            glColor3f(0.3f, 0.3f, rndNumber);
            glVertex2f(0.4f, 0.0f);
        glEnd();

        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) takeAndLoadScreenshot(typeScreenshot, 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) takeAndLoadScreenshot("bmp", 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) takeAndLoadScreenshot("png", 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) takeAndLoadScreenshot("jpg", 1000, 700);
       
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main()
{
    drawQuad("png", 1000, 700);

    return 0;
}

