# 1 
>main.cpp
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
    std::cout<< message<<std::endl;
}

>log.h
#pragma once 

void Log(const char* message);

# 2
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;
    bool ComparisionResult = x == 5; //"==" this operator equality operator which check if x=5 or not , if yes then it would give true and if not then it would give false
    if(ComparisionResult) //we doesn't need to write in brackets as (ComparisionResult == true) because that "if (ComparisionResult)" means same
    {
        Log("SolitaryBear");
    }
    
    std::cin.get();
}

# 3
>these all also works
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;
    
    if(x == 5)
    {
        Log("SolitaryBear");
    }
    
    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;

    if(83) //any no. other then 0 will works as true
    {
        Log("SolitaryBear");
    }
    
    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;

    if(x==5)
        Log("SolitaryBear"); //as its one line of code so we really don't need to require those brackets 
    
    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;

    if(x==5) Log("SolitaryBear"); //some people do this put in one line but i dont really preferred that, this gies problem while debugging 
    
    std::cin.get();
}
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    int x = 6;

    if(x) Log("SolitaryBear"); //some people do this put in one line but i dont really preferred that
    
    std::cin.get();
}
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = "SolitaryBear";

    if(ptr) // this we use to find null pointer , if prt isn't null then Log will execute other wise jump to the 11th line
        Log(ptr); 

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = nullptr; // now u can see through debugger doesn't run Log

    if(ptr) // this we use to find null pointer , if prt isn't null then Log will execute other wise jump to the 11th line
        Log(ptr); 

    std::cin.get();
}

> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = nullptr;

    if(ptr != nullptr) // another way
        Log(ptr ); 

    std::cin.get();
}
# 3
* if else statement
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = nullptr;

    if(ptr) 
        Log(ptr );
    
    else
         Log("ptr is NUll!");

    std::cin.get();
}
* else if statements
>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = "Hello";

    if(ptr) 
        Log(ptr );

    else if (ptr == "Hello") // **else if will only going to check the condition if the above "if" statement fails**
        Log ("ptr is Hello");    
    
    else
         Log("ptr is NUll!");

    std::cin.get();
}

>main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = "Hello";

    if(ptr) 
        Log(ptr );

    if (ptr == "Hello")
        Log ("ptr is Hello");    
    
    else
         Log("ptr is NUll!");

    std::cin.get();
}

//this code will endup by printing two things 
Hello
ptr is Hello


# else if statement is little bit of trick 
> main.cpp
#include <iostream>
#include "log.h"

int main()
{
    const char* ptr = "Hello";

    if(ptr) 
        Log(ptr );

    else if (ptr == "Hello") // what if I'll try to say that its else statement but actually it is two different statements 

        Log ("ptr is Hello");    


    std::cin.get();
}

>main.cpp
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
* so the else if is clever little of esle and if 