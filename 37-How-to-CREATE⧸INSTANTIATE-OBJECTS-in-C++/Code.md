# 1
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const String& name) :m_Name(name) {}

    const String& GetName() const  {return m_Name;}
};

int main()
{
    std::cin.get();
}

# 2 constructing an object on stack without specifying parameter ---
so this will call over default constructor 
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const String& name) :m_Name(name) {}

    const String& GetName() const  {return m_Name;}
};

int main()
{
    Entity entity;
    std::cout << entity.GetName() << std::endl;
    
    std::cin.get();
}

* OUTPUT
            Unknown


# 3 Constructing an object on stact with specifying parameter ---
now this time it will call another constructor that we created
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const String& name) :m_Name(name) {}

    const String& GetName() const  {return m_Name;}
};

int main()
{
    Entity entity = Entity("SolitaryBear"); //equivalent to Entity entity("SolitaryBear");
    std::cout << entity.GetName() << std::endl;
    
    std::cin.get();
} 


# 4 why we there would be reason you can't do this 
* let's write some code that would actually fail scopes don't necessarily need to be functions
    they could be if statements for loops or even empty scopes in which we just have curly brackets
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const String& name) :m_Name(name) {}

    const String& GetName() const  {return m_Name;}
};

int main()
{
    Entity* e; //creating a Entity pointer //e is basically a variable that points to an Entity
    {
        Entity entity("SolitaryBear");
        e = &entity;
        std::cout << entity.GetName() << std::endl;
    }
    std::cin.get();
}

* error: as soon as we are out of curly brackets the that "SolitaryBear" entity object is ended that means end of the "SolitaryBear" 
-- that's the end of that "SolitaryBear"--- I'm still here there 

>Reference -- Image  --> 1,2,3 and 4 from asset 

* so there are two reason we might not allocate on the stack first is Code # 4 
another is if the entity is too large or there are too many Entity then we are kinda out of space , stack is usually quite small 1 MB or more depends on the platform 





# 5 Heap allocation -- a solution for # 4
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}

    Entity(const String& name) :m_Name(name) {}

    const String& GetName() const  {return m_Name;}
};

int main()
{
    Entity* e; //creating a Entity pointer //e is basically a variable that points to an Entity
    {
        Entity* entity = new Entity("SolitaryBear"); // changes we made are Entity--> Entity * and the "new" keyword this "new" is the actually the key for allocating on the Heap  
        e = entity;
        std::cout << (*entity).GetName() << std::endl;
        delete entity; //delete keyword to delete allocated memory on the hewp by up ourself
    }
    std::cin.get();


    // delete entity;//we can also write that delete keyword here depending whenever we want to clean up heap

}


so when we call--- new Entity ---
that means we allocate memory on the heap
we call the constructor 
then the 'new Entity' actually return the Entity* ----> returns the location, on the heap the memory is allocated that's why we assign to the entity pointer 
.
.
Now after allocating memory on the heap we are responsible to clean memory on the heap

#
#
#
#
#
#
#
#
#
#
#
