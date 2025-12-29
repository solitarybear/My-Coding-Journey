#include <iostream>
//here we are declaring the log function the main difference btw declaration and definition is that declaration does have body but definition has.

void Log(const char* message);  //actually u don't need to specify the parameter name (message) because it doesn't important

int main()
{
    Log("Hello World!");
    std::cin.get();
}