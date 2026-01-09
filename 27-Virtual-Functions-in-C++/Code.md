# 1
>main.cpp
#include <iostream>
#include <string>
int main()
{
    std::cin.get();
}
# 2
>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    std::string GetName() {return "Entity";}
};

class Player : public Entity 
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() {return m_Name;};
};

int main()
{
    Entity* e = new Entity();
    std::cout<< e->GetName() <<std::endl;

    Player* p = new Player ("SolitaryBear");
    std::cout<< p-> GetName() << std::endl;
    
    std::cin.get();
}

# 3 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    std::string GetName() {return "Entity";}
};

class Player : public Entity 
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() {return m_Name;};
};

int main()
{
    Entity* e = new Entity();
    std::cout<< e->GetName() <<std::endl;

    Player* p = new Player ("SolitaryBear");
    std::cout<< p-> GetName() << std::endl;

    Entity* entity = p;
    std::cout<< entity-> GetName()<< std::endl;
    //if I run micro here you can see we get entity printing however we would have course expect SolitaryBear because even though we're referring to this entity as an entity pointer it is actually a player it's an instance of the player class
   
    std::cin.get();
}

* output
Entity 
SolitaryBear 
Entity


we were supposed to get 3rd print as SolitaryBear

# 4 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    std::string GetName() {return "Entity";}
};

class Player : public Entity 
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() {return m_Name;};
};

void PrintName (Entity* entity)
{
    std::cout<< entity -> GetName()<<std::endl;
}


int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player ("SolitaryBear");
    PrintName(p);

   
    
    std::cin.get();
}

* note:
p is a Player*
Player inherits from Entity

So in C++:
> A Player* can be treated as an Entity*

This is called upcasting.
.............................continued in handwritten notes 

* line 109 
when we call the get name function inside entity it's going to look at entity and just call get name that's it however we

want C++ to somehow realize that hang on a minute the entity that I passed into here is actually a player so please call this get name function

# 5 Using Virtual function 
* virtual functions that reduce something called dynamic dispatch 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() {return "Entity";}
};

class Player : public Entity 
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() {return m_Name;};
};

void PrintName (Entity* entity)
{
    std::cout<< entity -> GetName()<<std::endl;
}


int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player ("SolitaryBear");
    PrintName(p);

   
    
    std::cin.get();
}

# 6 Overridden Function 
another thing that we can do that was introduced in tables of 11 is actually marked this overridden function with the keyword override right over here this isn't required of course you can see that we just ran our code without that and it worked fine however you

should still do this it goes first of all it makes it a little bit more readable since we now know this is actually an overridden function but also it just helps us a little bit with preventing bugs tutors like spelling mistakes and all that


>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() {return "Entity";}
};

class Player : public Entity 
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() override {return m_Name;}; // added  overridden fuction 
};

void PrintName (Entity* entity)
{
    std::cout<< entity -> GetName()<<std::endl;
}


int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player ("SolitaryBear");
    PrintName(p);

   
    
    std::cin.get();
}


# 7



