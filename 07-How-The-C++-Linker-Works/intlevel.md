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

void Log(const char* message, int level ) 
// but when put void again and now put (, int level) beside message and then  we link we got a linking error  
{
    std::cout<< message << std::endl;
    //return 0; //used when int instead of void 
}

now linking both the files

## g++   math1.cpp log1.cpp -o math1log1intlevel
we got an error
/usr/bin/ld: /tmp/ccIO3eRh.o: in function `Multiply(int, int)':
math1.cpp:(.text+0x1d): undefined reference to `Log(char const*)'
collect2: error: ld returned 1 exit status


## because the log function (Log("Multiply");from math1.cpp) that it expects does not have another parameter
 cherno view( if see go down here into linking error message it actually expects a function which return void which has this calling convection it's called Log and it has to have just one parameter which is a const char pointer that's it 
 if it ain't gonna find exactly that we gonna get a linking error)