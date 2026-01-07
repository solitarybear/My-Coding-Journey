# 1
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Print ()
    {
        std::cout<< X << "," << Y << std::endl;
    }


};

int main()
{
    Entity e(7.0f,3.9f);
    e.Print();
    
    
    
    std::cin.get();

}

# 2 
>main.cpp 
#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity ()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" <<std::endl;
    }


    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }


    void Print ()
    {
        std::cout<< X << "," << Y << std::endl;
    }


};

int main()
{
    Entity e; //since this is stack allocated we will only see the destructure getting called when the main function exits
    
    //which we're not really going to see because our program will close immediately after that 

    e.Print();
    
    
    
    std::cin.get();

}

# 3 
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity ()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" <<std::endl;
    }


    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }


    void Print ()
    {
        std::cout<< X << "," << Y << std::endl;
    }


};

void Function ()
{
    Entity e; 
    e.Print();
}

int main()
{

    Function();
    std::cin.get();

}
* Output
Created Entity!
0,0
Destroyed Entity!


# 4  you can also call destructor manually
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity ()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" <<std::endl;
    }


    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }


    void Print ()
    {
        std::cout<< X << "," << Y << std::endl;
    }


};

void Function ()
{
    Entity e; 
    e.Print();
    e.~Entity();
}

int main()
{

    Function();
    std::cin.get();

}


* Output 
Created Entity!
0,0
Destroyed Entity!
Destroyed Entity!
