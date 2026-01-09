#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() {return "Entity";}

    std::string GetClassName() override {return "Entity";}
};

class Player : public Entity //as we inherited Entity class (which inherited Printable class so indirectly we have inherited Printable class in Player class)
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
    : m_Name(name) {}

    std::string GetName() override {return m_Name;}; // added  overridden fuction 

    std::string GetClassName() override {return "Player";}
};

class A : public Printable
{
public:
    std::string GetClassName() override {return "A";}
};




void Print(Printable* obj)
{
    std::cout<< obj-> GetClassName() << std::endl;
}

void PrintName (Entity* entity)
{
    std::cout<< entity -> GetName()<<std::endl;
}


int main()
{
    Entity* e = new Entity();
    //PrintName(e);

    Player* p = new Player ("SolitaryBear");
    //PrintName(p);

   Print(e);
   Print (p);
   Print(new A());
    
    std::cin.get();
}
