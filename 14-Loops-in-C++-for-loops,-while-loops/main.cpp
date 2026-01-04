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
    
    while (condition) //as in the while loop condition is false then it will skip the code 
    {
        //code
    }





    do                 //and here even if the condition is false it will run the body inside it once 
    {
        // code 
    } while (condition);
    



    std::cin.get();
}