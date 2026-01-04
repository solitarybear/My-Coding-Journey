# 1 
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    Log ("SolitaryBear");
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

void Log(const char* message);

# 2
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    Log ("SolitaryBear");
    Log ("SolitaryBear");
    Log ("SolitaryBear");
    Log ("SolitaryBear");
    Log ("SolitaryBear");
    std::cin.get();
}

# 3
#include <iostream>
#include "log.h"

int main()
{
    for (int i=0; i < 5; i++) // that u can put any variable instead of 'i' and also put any value equal to that variable instead of "0"
    {
        Log ("SolitaryBear");
    }

    std::cin.get();
}

> when the code run and comes to line 47 then 
<Declaration firstly it does declaration(sees the declaration) 
<Condition then it chekc the condition 

if its true then go inside the body and perform whatever written in the body

after completing the body (near curly bracket )
it wents to perform whatever code it written next to condition <i++

after that we are back to the condition check that if it is true so on 



# int i = 0  is declaration
# i < 5 is condition
 

* as we said above our below code means exactly like that
# modified #3
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int i=0;
    for ( ; i < 5; ) //if there nothing written in instead of i<5  then that black place is treated as true
    {
        Log ("SolitaryBear");
        i++;
    }

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int i=0;
    bool condition = i < 5;

    for ( ;condition ; ) 
    {
        Log ("SolitaryBear");
        i++;
        if  (!(i<5))
           condition = false;
    }

    std::cin.get();
}


* made by me
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int i=0;
    bool condition = i < 5;

    for ( ;condition ; ) 
    {
        Log ("SolitaryBear");
        i++;
        if (bool x= !(i<5))
           condition = false;
    }

    std::cin.get();
}

* made by me
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int i=0;
    bool condition = i < 5;

    for ( ;condition ; ) 
    {
        Log ("SolitaryBear");
        i++;
        bool condition = i < 5;
    }

    std::cin.get();
}

# 4 adding while loop
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        Log ("SolitaryBear");
    }
    
    Log ("============================");

    int i=0;
    while(i<5)
    {
        Log ("SolitaryBear");
        i++;
    }

    std::cin.get();
}

# 5 adding do while 
>main.cpp
#include <iostream>
#include "log.h"

int main()
{

    for (int i=0 ;i<5 ;i++ ) 
    {
        Log ("SolitaryBear");
    }
    
    Log ("============================");


    bool condition = false;
    
    while (condition)   //as in the while loop condition is false then it will skip the code 
    {
        //code
    }





    do                 //and here even if the condition is false it will run the body inside it once 
    {
        // code 
    } while (condition);
    



    std::cin.get();
}

