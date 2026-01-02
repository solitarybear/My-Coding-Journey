
#include <iostream>

int Multiply(int a , int b ) 
{
    return a*b ;
}

void aLog (int a, int b)
{
    int result = Multiply(a,b);
    std::cout<< result <<std::endl;

}


int main ()
{
    aLog (3,2);
    aLog (4,74);
    aLog (33,36);
    
    std::cin.get();

}