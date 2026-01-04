# 1
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        Log ("SolitaryBear");
    }

    std::cin.get();
}

>log.cpp
#include <iostream>
#include "log.h"

void Log(const char* message)
{
    std::cout<< message<< std::endl;
}

>log.h
#pragma once

void Log (const char* message);

# 2 continue ---control flow
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        Log ("SolitaryBear");
        continue;
    }

    std::cin.get();
}
//doesn't impact anything as after continue there already end of loop

* next 
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if(i % 2 == 0)
             continue;
        Log ("SolitaryBear");
    }

    std::cin.get();
}



>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( i% 2 == 0)
             continue;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( i > 2)
             continue;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( (i + 1) % 2 == 0)
             continue;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}



# 3 break  -----  Control Flow
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( i > 2)
             break;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if (i % 2 == 0)
             break;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( (i + 1) % 2 == 0)
             break;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}

# 4 returm
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        if( (i + 1) % 2 == 0)
             return;
        Log ("SolitaryBear");
        std::cout<< i << std::endl;
    }

    std::cin.get();
}



* error
[{
	"owner": "cpptools",
	"severity": 8,
	"message": "return-statement with no value, in function returning ‘int’ [-fpermissive]",
	"source": "gcc",
	"startLineNumber": 10,
	"startColumn": 14,
	"endLineNumber": 10,
	"endColumn": 14
}]
means as we are in int main so return must return a value 

>main.cpp
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

