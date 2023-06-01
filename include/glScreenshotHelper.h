/**
 * @file glScreenshotHelper.h
 * 
 * @brief Заголовочный файл библиотеки glScreenshotHelper
 * 
 * Данный файл содержит определение класса библиотеки
 * 
 */
#ifndef GL_SCREENSHOT_HELPER_H
#define GL_SCREENSHOT_HELPER_H

#include <vector>
#include <string>

namespace vniiftri
{
    namespace oscilloscope_gui
    {
        /**
         * @brief Класс для создания и загрузки скриншота в смонтированный каталог USB-накопителя
         */
        class ScreenshotHelper
        {
            public:
                /**
                 * @brief Функция создает название скриншота
                 * 
                 * @details
                 * 
                 * Название файла предстваляет из себя: 
                 * 
                 * screenshot - ключевое слово;  
                 * dd-mm-yy - дата создания;  
                 * hh:mm:ss - время создания;  
                 * .type - тип файла скриншота (.png, .jpg, .bmp).
                 * 
                 * Данная структура названия дает понять когда, в какое время и какого типа был создан файл скриншота.
                 * 
                 * @example
                 * 
                 * screenshot_01-06-23_10:00:00.png
                 * 
                 * @param type тип файла скриншота (.png, .jpg, .bmp) 
                 * @return std::string 
                 */
                static std::string i_tals_createFileName(const std::string type);

                /**
                 * @brief Функция ищет название смонтированного каталога USB-накопителя
                 * 
                 * @details
                 * 
                 * В библиотеке существует макрос DEFAULT_PATH, в котором содержится путь до каталога, куда монтируются USB-накопители. 
                 * Функция открывает данный каталог и осуществляет поиск смонтированного(ых) каталога USB-накопителя, 
                 * берет название каталога(ов) и сохраняет в вектор типа std::string.
                 * 
                 * @return std::vector<std::string> вектор, содержащий название(я) смонтированного(ых) каталога(ов) USB-накопителя
                 */
                static std::vector<std::string> i_tals_findCatalogUsbName();

                /**
                 * @brief Функция создает и загружает скриншот в смонтированный(е) каталог(и) USB-накопителя
                 * 
                 * @details
                 * 
                 * Поочередно вызваются функции: 
                 * 1. Функция создания названия скриншота.
                 * 2. Функция поиска названия(ий) сомнтированного(ых) каталога(ов) USB-накопителя. 
                 * 
                 * С помощью функции glReadPixels берется массив пикселей из фреймбуффера и при помощи функции FreeImage 
                 * данный массив пикселей преобразуется в файл скриншота с заданным типом. 
                 * Из вызванных ранее функций создается путь сохранения файла скриншота. 
                 * 
                 * PATH = DEFAULT_PATH/название_каталога_ USB-накопителя/название_скриншота.тип_файла_скриншота
                 * 
                 * @example
                 * 
                 * /home/linux/media/fleshka/screenshot_01-06-23_10:00:00.png
                 * 
                 * @param type тип файла скриншота (.png, .jpg, .bmp) 
                 * @param width ширина экрана в пикселях
                 * @param height высота экрана в пикселях
                 * @return int возвращенное значение 0 - функция отработала успешно, -1 - возникли ошибки в ходе работы функции
                 */
                static int i_tals_takeAndLoadScreenshot(const char *type, int width, int height);
        };
    }
}

#endif