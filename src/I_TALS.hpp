#ifndef I_TALS_H
#define I_TALS_H
#include <cstdint>

char *i_tals_createFilename(char *type);
char *i_tals_findCatalogUsbName();
void i_tals_takeAndLoadScreenshot(uint8_t *pixels, char *type, int width, int height);
uint8_t *gtpxls(int width, int height);

#endif