#include <iostream>
#include <string>

void PrintString(const std::string& string) //const because we are promissing not to write as string is in ROM, and reference because to not copy 
{
    std::cout << string << std::endl;

}

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 

    PrintString(name);



    bool contains = name.find("no") != std::string::npos;
    std::cout<< name <<std::endl;

    std::cin.get();
}