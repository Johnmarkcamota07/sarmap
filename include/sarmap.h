#ifndef SARMAP_H
#define SARMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations (No need for SARMAP_EXPORT since it's static-only)
char *inputSTR();
char **arraySTR(char *string, char **array);
void clearBuffer();

#endif // SARMAP_H
