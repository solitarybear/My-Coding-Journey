#include <iostream>
#include "log.h"



void InitLog()
{
    Log("Intialising Log");

}

void Log(const char* message)
{
    std::cout<< message <<std::endl;
}