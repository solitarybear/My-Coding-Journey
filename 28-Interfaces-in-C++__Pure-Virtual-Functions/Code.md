# 1 
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

# 2 natural virtual function
>main.cpp
#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() = 0; // we just had made it equal to 0 and now this is Pure Natural Fuction 
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
    Entity* e = new Player (""); 
    // we replace Entity by Player b'coz due to Natural function no need implementation of base class
    PrintName(e);

    Player* p = new Player ("SolitaryBear");
    PrintName(p);

   
    
    std::cin.get();
}

# 3 example for virtual function
>main.cpp
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
    
    std::cin.get();
}

* Output 
Entity
Entity 

>because we  haven't overide definition  in Player 

# 4 correctly the previous mistake 
>main.cpp
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
    
    std::cin.get();
}


# 5 Taking a completely new class 
in Print fuction Printable does't care about what class it is

>we are creating a new class A


>main.cpp
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


