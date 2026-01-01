## Now we will make header file  

* create a headerfile 
touch log1.h
 in the header file 

 #pragma once 

void Log(const char* message )  
{
    std::cout<< message << std::endl;
}


* and our log1.cpp file is like 
(we add there some new function)

#include <iostream>

void Initlog()
{
    Log("Intialized Log");
}


* math1.cpp
#include <iostream>
#include "log1.h" 
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

## when we compile log1.cpp 
there is error because we need log function to be define 


* error
g++ -c log1.cpp -o log1header
log1.cpp: In function ‘void Initlog()’:
log1.cpp:14:5: error: ‘Log’ was not declared in this scope
   14 |     Log("Intialized Log");
      |     ^~~



so we add
 #include "log1.h" 

now compiled sucessfully
command ---- g++ -c log1.cpp -o log1header1



## now we will make executable file from above file (in other words build)
command -- g++  log1.cpp math1.cpp  -o math1log1_log1h
now we got an error that looks like below

/usr/bin/ld: /tmp/ccuXyA9h.o: in function `Log(char const*)':
math1.cpp:(.text+0x0): multiple definition of `Log(char const*)'; /tmp/ccVa3uBd.o:log1.cpp:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status

* this error occured 
its stating that multiple definition of log (one or more multiply defined symbols found)
that is due to include headerfile 

## How include statements works 
* Remember when we include a headerfile we are just taking contents of that headerfile and putting it where our include statement is.
so log.h took the definition and put it in both the files log1.cpp and math1.cpp 
this became same to the case 2 of dublicate definition

## what we should do now 

1. add static before the void in the log.h file due to this when our file is putted in the other file linker will treat these definition as just 
>>"internal to those each file"
math1.cpp and  log1.cpp will have their own version of Log and it won't be visible for any other object file 

after doing so 
command -- g++  log1.cpp math1.cpp  -o math1log1_static    
>> our command is executed without error


2. Another thing we can do is to make it "inline void......."
>> inline means its going to take our actual function body and replace the call with it 

>> So in the log1.cpp case 
intial code 

#include <iostream>
#include "log1.h"
void Initlog()
{
    Log("Intialized Log");     
}

here in this case this log  intialized log would just become that 

//this code Log("Intialized Log") will become 

>> std::cout<< "Intialized Log"<< std::endl; // here message from log1.h is replaced by "Intialized Log" of log1.cpp

after doing so 
command -- g++  log1.cpp math1.cpp  -o math1log1_inline   
>> our command is executed without error 


3. in the first place the error is just to mutiply times of log fuction so we would do know is that from the header file will move the below code to either one of the file translation unit math1.cpp or log1.cpp

void Log(const char* message )  
{
    std::cout<< message << std::endl;
}
so we are putting it in log1.cpp 
and yes in log1.h we will left a declaration to log 
such that
>> void Log(const char* message ) ;

after doing so 
command -- g++  log1.cpp math1.cpp  -o math1log1_moving   
>> our command is executed without error 