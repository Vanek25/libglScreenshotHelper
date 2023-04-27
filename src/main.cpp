#include <GLFW/glfw3.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <string>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <vector>
#include <FreeImage.h>
#include "include/glScreenshotHelper.h"

void drawQuad(const char *typeScreenshot, int width, int height)
{
    ScreenshotHelper shelper;

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

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            shelper.takeAndLoadScreenshot(typeScreenshot, 1000, 700);

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
            shelper.takeAndLoadScreenshot("bmp", 1000, 700);

        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
            shelper.takeAndLoadScreenshot("png", 1000, 700);

        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
            shelper.takeAndLoadScreenshot("jpg", 1000, 700);

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
