#include "common.h"
#include "l2.h"

#include <iostream>




void InitLog()
{
    Log("Intialising Log");

}

void Log(const char* message)
{
    std::cout<< message <<std::endl;
}