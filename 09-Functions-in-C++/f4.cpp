
#include <iostream>

int Multiply(int a , int b ) 
{
    return a*b ;
}



int main ()
{
    int result = Multiply(3, 2);
    std::cout<< result << std::endl;
    
    
    int result2 = Multiply(4, 74);
    std::cout<< result << std::endl;
    
    int result3 = Multiply(33, 36);
    std::cout<< result << std::endl;
    
    
    
    std::cin.get();

}
// why we are getting repeated value because while copy pasting we forget to change the varialbe which we have to print
