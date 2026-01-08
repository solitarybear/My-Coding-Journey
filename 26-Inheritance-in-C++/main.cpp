#include <iostream>

class Entity
{
public:
    float X, Y;
    
    void Move (float xa ,float ya)
    {
        X += xa;
        Y += ya;

    }
};

class Player 
{
    const char* Name ;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;
    

    std::cin.get();

}
