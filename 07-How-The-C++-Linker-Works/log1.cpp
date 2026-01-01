#include <iostream>

void Log(const char* message ) //if we change void with int then we link math1.cpp and log1.cpp they show a linking error as the Log that declared they have void but here there is int  according cherno. But in real there we got no error explained in void-int,md
// but when put void again and now put (, int level) another parameter beside message and then  we link we got a linking error  
{
    std::cout<< message << std::endl;
    //return 0; //used when int instead of void 
}



