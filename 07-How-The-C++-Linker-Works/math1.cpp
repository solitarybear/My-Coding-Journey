//We are linking two files math1.cpp and log1.cpp just to understand how linking works 
#include <iostream>

void Log(const char* message);



static int Multiply(int a, int b) //static we used for internal linking explained in static.md and notes 
{
    Log("Multiply");
    return a*b ;
}

 int main()
 {
   std::cout<< Multiply(69, 70)<<std::endl;
    std::cin.get();

 }