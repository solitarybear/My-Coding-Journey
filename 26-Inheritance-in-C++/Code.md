# 1
>main.cpp
#include <iostream>

int main()
{
    std::cin.get();

}
# 2 
>main.cpp
#include <iostream>

class Entity
{
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

    float X, Y;
    
    void Move (float xa ,float ya)
    {
        X += xa;
        Y += ya;

    }

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    std::cin.get();

}

# 3 Let's get Player to be a sub Class of Entity  
>main.cpp
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

class Player : public Entity
{
    const char* Name ;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    Player player;
    player.Move(2,7);
    player.X = 2;

    std::cin.get();

}

# 4 
>main.cpp
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

class Player : public Entity
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
    std::cout << sizeof(Player) << std::endl; // 
    

    std::cin.get();

}

* Output 
8,16

>if Player did not extend Entity then output will be
8,8
