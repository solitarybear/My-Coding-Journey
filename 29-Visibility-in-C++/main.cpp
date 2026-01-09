#include <iostream>
#include <string>

class Entity
{
public: //even if don't write this private class is set to private by default 
    int X, Y ;
    void Print(){}

public:
    Entity()
    {
        X=0;           // accessible 

        Print();      // accessible

    }
};

class Player: public Entity
{
    Player()
    {
        X =5;      //accessible
        Print ();   // accessible 
    }

};


int main()
{
    Entity e;
    e.X ;      //accessible 
    
    e.Print(); // accessible 

    std::cin.get();
}
