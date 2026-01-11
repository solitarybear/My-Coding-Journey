#include <iostream>
#include <string>

#include <stdlib.h> 
#include <cstring>  

int main()
{
    char name[] = "SolitaryBear";

    name[3] = 'e'; // we can do this because refer to either video or Video Notes 
    // inshort in .asm file we found out that we gotten that SolitaryBear segment and copied into a name variable 
    //o we've actually created an actual variable here before if we don't write this code what we're trying to do is modify the pointer that points to that constant data segment so we're actually trying to write it into the constant data here is create another variabl

    std::cout<< strlen(name) <<std::endl; 

    std::cin.get();
}
