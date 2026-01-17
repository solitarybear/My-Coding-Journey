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