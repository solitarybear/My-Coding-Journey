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
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string name)
        :m_Name(name), m_Age(-1) {}
    
    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};


int main()
{
    //Entity a("SolitaryBear");        //Entity a = Entity ("SolitaryBear");
    //Entity b(22); //Equivalent to  //Entity b = Entity (22);

    Entity a = "SolitaryBear"; //there is an error you can see in mynotes.md 
    Entity b = 22 ; //this is known as implicit conversion or implicit construction 
    std::cin.get();
}



* error in line ---- Entity a = "SolitaryBear"; 

* implicit conversion or illicit construction it's implicitly converting that 22 into an axiom constructing an entity out of it because there's a constructor fantasy which takes in an integer age right and there's a constructor fantasy which takes in a name


# 3 another example 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string name)
        :m_Name(name), m_Age(-1) {}
    
    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) //so its an function which takes an Entity but we see below 
{
    //printing //some printing stuff
}

int main()
{
    PrintEntity(22); //we can call the funtion with 22 ..but wait we haven't overloaded a printentity which takes an integer value 

    Entity a = "SolitaryBear";  
    Entity b = 22 ; //this is known as implicit conversion or implicit construction 
    std::cin.get();
}



*  we'll hang on a minute we don't have an overload for PrintEntity which takes in an integer or something like that we've just got one that takes in an entity but remember as far as c++ is concerned 22 can be converted into an entity because you can call this constructor and suddenly from 22 which is the only parameter you've made an entity




# 4 "SolitaryBear" for PrintEntity doesn't work
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string name)
        :m_Name(name), m_Age(-1) {}
    
    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) //so its an function which takes an Entity but we see below 
{
    //printing //some printing stuff
}

int main()
{
    PrintEntity(22); //we can call the funtion with 22 ..but wait we haven't overloaded a printentity which takes an integer value 
    
    PrintEntity("SolitaryBear");//this doesn't work because this isn't an std string this is an const char array[13];


    Entity a = "SolitaryBear";  
    Entity b = 22 ; //this is known as implicit conversion or implicit construction 
    std::cin.get();
}


> PrintEntity("SolitaryBear");
* in order for this to work C++ would actually have to do two conversions one from a Const RA into a string and then one from a string to an entity and it's only allowed to do one implicit conversion 




# 5 solution to code 4
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string name)
        :m_Name(name), m_Age(-1) {}
    
    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) //so its an function which takes an Entity but we see below 
{
    //printing //some printing stuff
}

int main()
{
    PrintEntity(22); //we can call the funtion with 22 ..but wait we haven't overloaded a printentity which takes an integer value 
    
    //PrintEntity(std::string ("SolitaryBear"));//this can be solution
    PrintEntity(Entity("SolitaryBear")); // we can also wrap it in an Entity


    Entity a = "SolitaryBear";  
    Entity b = 22 ; //this is known as implicit conversion or implicit construction 
    std::cin.get();
}

> PrintEntity(Entity("SolitaryBear"));
* that would work as well because in this case it would be implicitly converting this string into a string into an STD string into a standard string and then that will be pushed into the HD constructor and constructor available




# personaly cherno avoid this implicit conversion, normal way we would be better most of the time 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string name)
        :m_Name(name), m_Age(-1) {}
    
    Entity(int age)
        :m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) //so its an function which takes an Entity but we see below 
{
    //printing //some printing stuff
}

int main()
{

    Entity b (22);
    std::cin.get();
}

# 6 Explicit Keyword
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(const std::string name)   //here we also written Explicit constructor 
        :m_Name(name), m_Age(-1) {}
    
    explicit Entity(int age)                  //explicity constructor
        :m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) //so its an function which takes an Entity but we see below 
{
    //printing //some printing stuff
}

int main()
{
    PrintEntity(22); //this will also fails 
    
    PrintEntity(Entity("SolitaryBear"));   //this will work beacuse we are actually calling a constructor ---> Entity("SolitaryBear")

 
    Entity a = "SolitaryBear";  //this will fail as well because of explicit contructor 
   
   
   
    //Entity b = 22 ;           //there will be error this doesn't work due to explicit constructor
    Entity b(22);               //this we have to do in case of explicit constructor or either below one 
    Entity b = (Entity) 22 ;    //this is type casting 
    Entity b = Entity(22);      //this will also works 
   
   
   
    std::cin.get();
}

* that is really the only function of that explicit keyword it's for when you want your constructors to be explicitly called instead of allowing the C++ compiler to implicitly convert any integer into entity by just basically calling this constructor every time you try and do that 



#