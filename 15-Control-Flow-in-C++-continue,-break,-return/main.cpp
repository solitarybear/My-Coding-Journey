#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( (i + 1) % 2 == 0)
             return 0;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}

