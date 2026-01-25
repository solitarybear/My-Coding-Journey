#include <iostream>
#include <string>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity ()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};



class ScopedPtr //we are writing our own scoped pointer so that you can see how it works 
{
private:
    Entity* m_ptr;

public:
    ScopedPtr(Entity* ptr)
        :m_ptr(ptr)
    {

    }


    ~ScopedPtr()
    {
        delete m_ptr;
    }
};
//so this is a basic scoped pointer 



int main()
{
    {  
        ScopedPtr e = new Entity(); // we could also written this wth the default constructor----- ScopedPtr e (new Entity());
        //also this above works like implicit conversion 
        
        
        
        //Entity* e = new Entity(); // after this allocation i want to automatically delete after the out of the scope
        //we can do this with something in the standard libraby known a unique pointer or scoped pointer 

    }


    std::cin.get();
}