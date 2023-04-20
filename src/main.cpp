#define _DEFAULT_SOURCE

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
    tm *dateTimeNow = localtime(&t);
 
    char filename[64];
    strftime(filename, sizeof(filename), "screenshot_%d-%m-%y_%X.", dateTimeNow);
    
    char *buffer = new char[strlen(filename) + strlen(type) + 1];
    
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

    char *pathToLoadScreenshot = new char[strlen(DEFAULT_PATH) + strlen(i_tals_findCatalogUsbName()) + strlen(i_tals_createFilename(type))];

    strcpy(pathToLoadScreenshot, DEFAULT_PATH);
    strcat(pathToLoadScreenshot, i_tals_findCatalogUsbName());
    strcat(pathToLoadScreenshot, i_tals_createFilename(type));

    printf(pathToLoadScreenshot);
    printf("\n");

    if(type == "bmp") FreeImage_Save(FIF_BMP, image, pathToLoadScreenshot, 0);
    else if(type == "jpg") FreeImage_Save(FIF_JPEG, image, pathToLoadScreenshot, 0);
    else if(type == "png") FreeImage_Save(FIF_PNG, image, pathToLoadScreenshot, 0);
    
    FreeImage_Unload(image);

    delete pixels;
    delete pathToLoadScreenshot;
}


void drawQuad(char *typeScreenshot, int width, int height)
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

        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) i_tals_takeAndLoadScreenshot(typeScreenshot, 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) i_tals_takeAndLoadScreenshot("bmp", 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) i_tals_takeAndLoadScreenshot("png", 1000, 700);

        if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) i_tals_takeAndLoadScreenshot("jpg", 1000, 700);
        
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

