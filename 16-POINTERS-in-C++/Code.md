# 1
>main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    std::cin.get();
}

# 2
> main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    int var = 8;
    void* ptr = nullptr;
    std::cin.get();
}

>main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    int var = 8;
    int* ptr = &var;
    std::cin.get();
}
//see image 3 in assets

>main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    int var = 8;
    double* ptr = (double*)&var; // if we write double and just &var then would be an error // because a value of type "int" cannot be used to initialize an entity of type "double"
    std::cin.get();
}
>that (double*)&var here this (double*) is means ---> cast it to double

# 3
>main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    int var = 8;
    void* ptr = &var; 
    *ptr =10;

    std::cin.get();
     
}
* error 
we wrote *ptr = 10;

>error because we set ptr as void
how would a computer would write the value 10 into a void pointer, it doesn't know what it is 
is that 10 is short which is a 2 byte integer 
is it a int which is a 4 byte integer
is it a long long which is 8 byte integer 

we don't know how many bytes of data should we write we just said 10 ,10 could be anything 

that's where type comes in we need to tell compiler actually know this is an integer so i expect u to write 4 bytes in please
* "we told the compiler" 

>main.cpp
#include <iostream>

#define LOG(x) std::cout<< x << std::endl;

int main()
{
    int var = 8;
    int* ptr = &var; 
    *ptr =10;
    LOG (var);

    std::cin.get();
     
}

* so far we've been directly creating data on the stack if I create a variable like this we're creating it in the stack portion of our memory

# 4 pointer in heap memory
>main.cpp
#include <iostream>
#include <cstring>
#define LOG(x) std::cout<< x << std::endl;

int main()
{
    char* buffer = new char[8];  //new char[8] this allocates 8 bytes of memory for us and its returning a pointer to the beginnig of that block of memory 
   
    memset(buffer,0,8); // memset ("takes a pointer ---> buffer"  ; "its going to take a value----> 0 "  ; "how many bytes should it fill " ) this is the function which basically fills the block of memory with data we specify it 

    std::cin.get();
     
}


>main.cpp
#include <iostream>
#include <cstring>
#define LOG(x) std::cout<< x << std::endl;

int main()
{
    char* buffer = new char[8];
    memset(buffer,0,8); 

    
    delete [] buffer; 


    std::cin.get();
     
}
* in this case because we use the new keyword and this data is actually Heap allocated we should also delete the data when we're done with it and we can do that just by typing in delete we know it's an array we use the array operator to allocate it so we should use the delete keyword with the array operator and then delete that buffer if we were being super nice however our program does finish

>main.cpp
#include <iostream>
#include <cstring>
#define LOG(x) std::cout<< x << std::endl;

int main()
{
    char* buffer = new char[8]; 
    memset(buffer,0,8); 

    char** ptr = &buffer; //char** is means double pointer, as pointer points to variable , double pointer points to pointer
    delete[] buffer; 

    std::cin.get();
     
}