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