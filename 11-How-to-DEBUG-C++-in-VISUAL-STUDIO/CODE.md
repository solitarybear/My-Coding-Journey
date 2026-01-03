
# 1
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    Log("SolitaryBear");
    std::cin.get(); 
}

>log.cpp
#include <iostream>
#include "log.h"

void Log(const char* message)
{
    std::cout<< message << std::endl;
}

>log.c
#pragma once

void Log(const char* message);

# 2
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int a = 8;
    a++;
    const char* string ="Hello";

    for (int i=0; i < 5; i++ )
    {
        const char c = string[i];
        std::cout<< c <<std::endl;
    }

    Log("SolitaryBear");
    std::cin.get(); 
}