## math1.cpp is

#include <iostream>

void Log(const char* message);


static int Multiply(int a, int b) 
{
    Log("Multiply");
    return a*b ;
}

 int main()
 {
   std::cout<< Multiply(69, 70)<<std::endl;
    std::cin.get();

 } 


 ## And log1.cpp
 #include <iostream>

void Log(const char* message )  
{
    std::cout<< message << std::endl;
}

void Log(const char* message)  
{
    std::cout<< message << std::endl;
}

now linking both the files

command 
  g++   math1.cpp log1.cpp -o math1log1dublicate

## Our way (gcc way) we  get error state below 
 g++   math1.cpp log1.cpp -o math1log1dublicate
log1.cpp:10:6: error: redefinition of ‘void Log(const char*)’
   10 | void Log(const char* message )
      |      ^~~
log1.cpp:3:6: note: ‘void Log(const char*)’ previously defined here
    3 | void Log(const char* message ) //if we change void with int then we link math1.cpp and log1.cpp they show a linking error as the Log that declared they have void but here there is int  according cherno. But in real there we got no error explained in void-int,md
      |      ^~~

## the cherno way it tries build then he got a compiler error stating 
it already have a body and hey im compiling this file and i can say that you have made a mistake and i know that this code isn't valid 



## Another way
## math1.cpp is

#include <iostream>

void Log(const char* message);

void Log(const char* message)  
{
    std::cout<< message << std::endl;
}


static int Multiply(int a, int b) 
{
    Log("Multiply");
    return a*b ;
}

 int main()
 {
   std::cout<< Multiply(69, 70)<<std::endl;
    std::cin.get();

 } 


 ## And log1.cpp
 #include <iostream>

void Log(const char* message )  
{
    std::cout<< message << std::endl;
}


# now compiling each file 
command -- g++ -c math1.cpp -o math1dublicate1-------------successfully runned 
command -- g++ -c log1.cpp -o log1dublicate1 ---------------successfully runned 


## now linking both the files

command 
  g++   math1.cpp log1.cpp -o math1log1dublicate1  ---------- shows error

   g++   math1.cpp log1.cpp -o math1log1dublicate
1
/usr/bin/ld: /tmp/cccqmFkC.o: in function `Log(char const*)':
log1.cpp:(.text+0x0): multiple definition of `Log(char const*)'; /tmp/ccRwev5I.o:math1.cpp:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status

* that is linking error stating Log funtion is already defined in object file of log1 , One or more multiplie define function 
* in this case linker doesnt know which log function to link to does it in log1.cpp or math1.cpp




