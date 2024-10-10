

#include <stdio.h>
#include <stdarg.h>
#include "headers/log.h"

int globalDebug = TRUE;

void SNLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){
    static int iCallCounter = 0;
    static FILE *fLogFile;
    if (fLogFile == NULL){
        fLogFile = fopen("debug.txt", "w");
    }

    va_list vaArgumentPointer;
    char szOutputString[256] = {0};
    const char *pszType;

    switch (ulErrorType) {
        case 0:
            pszType = "Error";
            break;
        case 1:
            pszType = "Debug";
            break;
        case 2:
            pszType = "Info";
            break;
        default:
            pszType = "Unknown";
            break;
    }

    va_start(vaArgumentPointer, pszFormat);
    vsnprintf(szOutputString, 256-1, pszFormat, vaArgumentPointer);
    va_end(vaArgumentPointer);

    fprintf(fLogFile, "%04i: %s:%s Path: %s:%i\n", iCallCounter, pszType, szOutputString, szFile, iLine);
    iCallCounter++;
}