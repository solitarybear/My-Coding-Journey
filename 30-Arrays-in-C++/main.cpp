#include <iostream>
#include <array>

class Entity
{ 
public:
    static const int ExampleSize = 5; // this will helps to works 
    int example[ExampleSize];

    std::array < int, 5> another;  // this is C++ 11 standard array  

    Entity ()
    {
        for (int i = 0 ;i < another.size() ; i++) //ofcourse we really so another .size() here 
        example[i] = 2;

    }
};

int main()
{
    Entity e; 

    std::cin.get();
}
