#include <iostream>

int Multiply(int a , int b ) //if we dont want to return anything we just write void instead of int
{
    return a*b ;
}



int main ()
{
    int result = Multiply(3, 2);



    std::cout<< result << std::endl;
    std::cin.get();

}