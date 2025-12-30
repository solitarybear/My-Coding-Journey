#include <iostream>
//here we are declaring the log function, the main difference btw declaration and definition is that declaration does not have body but definition has.
//for now all u have to know is that const char function is basically A TYPE that can hold a string of text 
void Log(const char* message);  //actually u don't need to specify the parameter name (message) because it doesn't important  {
     //{
     //   std::cout << message << std::endl;                             
     //}
int main()
{
    Log("Hello World!");
    std::cin.get();
}