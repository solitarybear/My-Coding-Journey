//#include "common.h"
//#include "l2.h"

#include <iostream>


#ifndef  _LOG_H
#define _LOG_H



void InitLog();
void Log(const char* message);

struct player{};


#endif



#ifndef  _LOG_H
#define _LOG_H



void InitLog();
void Log(const char* message);

struct player{};


#endif



void InitLog()
{
    Log("Intialising Log");

}

void Log(const char* message)
{
    std::cout<< message <<std::endl;
}