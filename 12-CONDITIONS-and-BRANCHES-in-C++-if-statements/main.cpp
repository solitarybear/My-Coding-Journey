#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = "Hello";

    if(ptr) 
        Log(ptr );

    else
        {
            if (ptr == "Hello")
                 Log ("ptr is Hello");    
        }


    std::cin.get();
}