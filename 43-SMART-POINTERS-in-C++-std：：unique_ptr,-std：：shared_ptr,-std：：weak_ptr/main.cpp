#include <iostream>
#include <string>
#include <memory> //to access to all the smart pointer 
class Entity
{
public:
    Entity ()
    {
        std::cout << "Entity Created!" << std::endl;
    }

    ~Entity ()
    {
        std::cout << "Entity Destroyed!" << std::endl;
    }


    void Print() {}
};


int main()
{
    {
        std::weak_ptr <Entity> e0;
        {
            std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity>();
            std::weak_ptr <Entity> weakEntity = sharedEntity; //there will be copy of shared pointer but doen't increase in reference count as happen usually 
            e0 = sharedEntity;
        }

    }


    std::cin.get();
}