
#include <iostream>

int Multiply(int a , int b ) 
{
    return a*b ;
}



int main ()
{
    int result = Multiply(3, 2);
    std::cout<< result << std::endl;
    //its to annaoing and multiple calling the function such to make[Multiply(3, 2)---- 3*2]
    
    int result2 = Multiply(4, 74);
    std::cout<< result2 << std::endl;
    
    int result3 = Multiply(33, 36);
    std::cout<< result3 << std::endl;
    
    
    
    std::cin.get();

}