#ifndef I_TALS_H
#define I_TALS_H

char *i_tals_createFilename(char *type);
char *i_tals_findCatalogUsbName();
void i_tals_takeAndLoadScreenshot(char *type, int width, int height);

#endif