# 1 
> main.cpp
#include <iostream>
#include <string>

class Entity
{

};

class Player
{

};


int main()
{
    
    std::cin.get();
}


# 2 private 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private: //even if don't write this private class is set to private by default 
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
        X =5;      //showing error such that member Entity::X is in accessible
        Print ();   // here too the print function is inaccessible 
    }

};


int main()
{
    Entity e;
    e.X ;      //outside the class Entity private members are inaccessible 
    
    e.Print(); // inaccessible 

    std::cin.get();
}


# 3 protected 
* protected means that this class of course there's empty class and all subclasses along the hierarchy can also access these symbols
>main.cpp
#include <iostream>
#include <string>

class Entity
{
protected: //even if don't write this private class is set to private by default 
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
    e.X ;      //outside the class Entity and heirarchy protected members are inaccessible 
    
    e.Print(); // inaccessible 

    std::cin.get();
}

# 4 public 
public 
all can access
>main.cpp
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


# 5
# 6
