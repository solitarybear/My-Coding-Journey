#include <iostream>
#include <string>

int main()
{
    

    int x = 8 ;
    auto f = [=]() mutable // due to mutable we can change the value of variable inside this lamdaa
    {
        x++; //what does lamdaa do here is that assign a local variable same as # 5
        std::cout << x << std::endl;

    };

    f(); 
    // now as we captured by value so outside the lamdaa, the variable will be same as before 
    // x will still be 8
    // because inside lamda function the calculation performed was on local variable as we done in #5
    // if we capture by & and the value can be changea 


    std::cin.get();
}