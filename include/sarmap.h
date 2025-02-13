#ifndef SARMAP_H
#define SARMAP_H

#ifdef _WIN32
    #ifdef BUILD_SARMAP
        #define SARMAP_EXPORT __declspec(dllexport)  // Export symbols when building DLL
    #else
        #define SARMAP_EXPORT __declspec(dllimport)  // Import symbols when using DLL
    #endif
#else
    #define SARMAP_EXPORT   // No special directive needed for static/shared on Linux/macOS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
SARMAP_EXPORT char *inputSTR();
SARMAP_EXPORT char **arraySTR(char *string, char **array);
SARMAP_EXPORT void clearBuffer();
#endif // SARMAP_H
