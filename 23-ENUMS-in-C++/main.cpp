#include <iostream>

enum Example :  char  //here is specify which type of integer you want this enum to be
{
    A=6, B=1, C               // we can also assign intergers to these variables as well            

};

int main()
{
    Example value = A;

    if 
     (value == B) // at the end of the day A, B, C  are integer so instead this we can also write (value == 1)
     {
        // Do something here
     }
    std::cin.get();
}