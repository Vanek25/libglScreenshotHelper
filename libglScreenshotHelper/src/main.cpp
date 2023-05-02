#include <GLFW/glfw3.h>
#include "../include/glScreenshotHelper.h"
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

void drawQuad(const char *typeScreenshot, int width, int height)
{
    ScreenshotHelper sHelper;

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
        {
            try
            {
                sHelper.takeAndLoadScreenshot(typeScreenshot, 1000, 700);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        {
            try
            {
                sHelper.takeAndLoadScreenshot("bmp", 1000, 700);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
 
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        {
            try
            {
                sHelper.takeAndLoadScreenshot("png", 1000, 700);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }   

        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        {
            try
            {
                sHelper.takeAndLoadScreenshot("jpg", 1000, 700);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int runTests()
{
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    CppUnit::TextTestRunner runner;
    runner.addTest(suite);

    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));
    bool wasSucessful = runner.run();
    return wasSucessful ? 0 : 1;
}

int main()
{
    drawQuad("png", 1000, 700);
    //return runTests();

    return 0;
}
