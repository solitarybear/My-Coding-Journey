//#include "common.h"
#include "l3.h"        // if want to go to one directory pass for header file then it will be like #include "../l2.h"  this go back to directory

#include "iostream"
//#include <stdlib.h>


void InitLog()
{
    Log("Intialising Log");

}

void Log(const char* message)
{
    std::cout<< message <<std::endl;
}