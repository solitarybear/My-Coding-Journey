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