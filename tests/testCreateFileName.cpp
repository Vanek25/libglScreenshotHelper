#include <dirent.h>
#include <vector>
#include <ctime>
#include <cstring>
#include <string>
#include <iostream>
#include <chrono>
#include "testCreateFileName.h"
#include <libglScreenshotHelper/glScreenshotHelper.h>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        CPPUNIT_TEST_SUITE_REGISTRATION (TestCreateFileName);

        void TestCreateFileName::setUp(){}

        void TestCreateFileName::tearDown(){}

        void TestCreateFileName::test_i_tals_createFileName()
        {
            ScreenshotHelper sHelper;

            const char *type = "jpg";

            // auto time = std::time(nullptr);
            // std::tm* dateTimeNow = std::localtime(&time);
            
            // char shrtFileName[64];
            // strftime(shrtFileName, sizeof(shrtFileName), "screenshot_%d-%m-%y_%X.", dateTimeNow);

            // char *fileName = new char[strlen(shrtFileName) + strlen(type)];

            // strcpy(fileName, shrtFileName);
            // strcat(fileName, type);

            time_t t = time(nullptr);
            tm *dateTimeNow = localtime(&t);
            

            std::string s = "screenshot_";
            char *c = s.data();


            char shrtFileName[100];
            strftime(c, sizeof(c), "screenshot_%d-%m-%y_%X.", dateTimeNow);
            
            //strcpy(shrtFileName, "aaa");

            char *fileName = new char[strlen(c) + strlen("jpg")];

            strcpy(fileName, c);
            strcat(fileName, "jpg");

            char *fileNameFromLib = sHelper.i_tals_createFileName("jpg");
            if(strcmp(fileName, fileNameFromLib) == 0)
            {
                std::cout<<std::endl;
                std::cout<<"Количество символов равно"<<std::endl;
            }
            
            CPPUNIT_ASSERT_EQUAL(fileNameFromLib, fileName);   
        }
    }
}