# 1
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

int main()
{

    std::cin.get();
}
# 2
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

int main()
{
    int a = 5 ;
    int& ref = a;


    std::cin.get();
}
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

int main()
{
    int a = 5 ;
    int& ref = a;

    ref = 2;

    LOG (a);


    std::cin.get();
}

# 3
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int value)
{
    value++;
}

int main()
{
    int a = 5 ;
    increment(a);

    LOG (a);


    std::cin.get();
}

* so what above code is doing is that its copying the value of a to the function increment such that above main.cpp is equivalent to below

>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int value)
{
    int value=5;// that we just copy the value of a and here it made a brand new variable 
    value++;
}

int main()
{
    int a = 5 ;
    increment(a);

    LOG (a);


    std::cin.get();
}
# 4 via pointer and dereference
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int* value)
{
    (*value)++;
}

int main()
{
    int a = 5 ;
    increment(&a);

    LOG (a);


    std::cin.get();
}
# 5 via reference
>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int& value)
{
    value++;
}

int main()
{
    int a = 5 ;
    
    increment(a);

    LOG (a);


    std::cin.get();
}
# 6 
>main.cpp
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

    int& ref = a;
    ref=b;            
    // if we print these both value  a=8 ,b=8 
    //increment(a);

    LOG (a);


    std::cin.get();
}

>main.cpp
#include <iostream>
#define LOG(x) std::cout<< x <<std::endl

void increment(int& value)
{
    value++;
}

>int main()
{
    int a = 5 ;
    int b=8;

    int& ref ; // when u declare a reference to have to assign it something, it require to initialzer
    ref=b;
    
    //increment(a);

    LOG (a);


    std::cin.get();
}
* error


# 7 now what should we do if we actually want this kinda functionality(reference)
>main.cpp
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