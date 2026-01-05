#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int& value)
{
    value++;
}

int main()
{
    int a = 5 ;
    int b=8;

    int* ref = &a;
    *ref = 2;

    ref = &b;
    *ref = 1;
    
    //increment(a);

    LOG (a);
    LOG (b);


    std::cin.get();
}