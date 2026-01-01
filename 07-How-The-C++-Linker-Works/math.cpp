#include <iostream>

void Log(const char* message)
{
    std::cout<< message << std::endl;
}

int Multiply(int a, int b)
{
    Log ("Multiply");
    return a*b;
}

 int main()
 {
    std::cout<< Multiply(5 , 8)<<std::endl;
    std::cin.get();

 }
 //now we will perform this above program what if they were in multiple files 