#include <iostream>
#include <string>

void PrintEntity(const Entity& e);

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;

        Entity& e =*this; //in case non const method we will get entity reference back

        PrintEntity(*this); //so we are derefencing here\

        delete this; //we can also do this 
    }

    int GetX() const //marking this as const is pretty much common
    {
        const Entity& e = *this; //so in a const method we  would get const refenerce back
        return x;
    }
};

void PrintEntity(Entity* e)
{
    //wanna do some printing kinda stuff
}

int main()
{
    std::cin.get();
}


