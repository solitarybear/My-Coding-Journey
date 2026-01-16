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
    Entity() :m_Name ("Unknown"){}
    Entity(const String& name) :m_Name(name){}

    const String& GetName() const {return m_Name; }
};

int main()
{
    std::cin.get();
}


# 2 
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() :m_Name ("Unknown"){}
    Entity(const String& name) :m_Name(name){}

    const String& GetName() const {return m_Name; }
};

int main()
{
    int a = 2 ;
    int* b = new int; // single 4 byte integer allocated on the heap 
    int* c = new int[50]; // 200bytes // if we want to allocated array on heap 
    
    Entity* e = new Entity(); // we can also write new Entity; instead this will call the default contructor

    //Entity* e = new Entity[50] ; //if we want an array of entities 
    
    std::cin.get();
}




# 3 what new actually does behind the scenes
what new actually does behind the scenes and strategies speaking this is actually dependent on the C++ library so of course Bureau your own C++ compiler with your own C++ library because theoretically make it do anything you wanted 

but usually usually pulling 'new' will call the underlying state function malloc which that's for memory allocate and what this will actually do you'll note is taking a size of how many fights we want and return a void pointer so that's really all it does so that being said this code is actually kind of equivalent to if we just written malloc sizeof entity like that and then of course cost this back into an end to see something we wouldn't have had to do in C but we

do in C++ but the difference between these two lines of code the only difference between these two lines of code is the fact that this will actually call the entity constructor whereas what this will do is purely allocate the memory and then give us a pointer to that memory not calling the constructor 

>malloc(50) ---- takes the size how many we want and returns a void pointer 


>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() :m_Name ("Unknown"){}
    Entity(const String& name) :m_Name(name){}

    const String& GetName() const {return m_Name; }
};

int main()
{
    int a = 2 ;
    int* b = new int; 
    int* c = new int[50]; // 200 bytes 
    
    Entity* e = new Entity(); // this will call the default contructor
    //Entity* e = (Entity*)malloc(sizeof(Entity));//kind of equivalent to just above line of code, but difference is it doesn't call the constructor 

    //free(e); //delete is the regular fuction that calls the c function free(e);
    delete e;
    delete b;
    delete[] c; // if we allocated new with square brackets(as we did for array) then we have to use delete with square brackets. 


    std::cin.get();
}


* note 
    you should not allocating memory like this in C++ 
-------------------------------------------------------Entity* e = (Entity*)malloc(sizeof(Entity));

##  must use delete
when you do use the new keyword you have to remember that you must use delete so once we allocate all these variables like B and E we have to use the delete keyword which is also an operator

 


# 4 Placement 'new'
>main.cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() :m_Name ("Unknown"){}
    Entity(const String& name) :m_Name(name){}

    const String& GetName() const {return m_Name; }
};

int main()
{
    int a = 2 ;
    int* b = new int; 
    int* c = new int[50]; // 200 bytes 
    
    Entity* e = new(b) Entity(); //here we specifying memory address for inistializing our entity in a specific memory address  


    delete e;
    delete b;
    delete[] c;
    std::cin.get();
}

>note 
one more thing that new actually supports is something called a placement in 'new' and that is where you actually get to decide kind of where the memory comes from so you're not really allocating memory 
in this case you're just calling the constructor and initializing your entity in a specific memory address and the way you do that is just by writing parenthesis like this and then specifying a memory address such as well B in this case I mean it would theoretically work because I'm assuming that entity is gonna be less than 200 bytes definitely


# 
