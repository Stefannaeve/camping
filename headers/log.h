//
// Created by Stefan on 04/10/2024.
//

#pragma once
extern int globalDebug;

#ifndef TELTTUR_LOG_H
#define TELTTUR_LOG_H

void SNLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...);

#define TRUE 1
#define FALSE 0

#define logError(...) SNLogger(0, __LINE__, __FILE__, __VA_ARGS__)
#define logDebug(...) if(globalDebug == TRUE){SNLogger(1, __LINE__, __FILE__, __VA_ARGS__);}
#define logInfo(...) SNLogger(2, __LINE__, __FILE__, __VA_ARGS__)

#endif //TELTTUR_LOG_H
