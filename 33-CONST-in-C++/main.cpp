#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 
    mutable int var; 

public:
    int  GetX() const 
    { 
        var =2 ;
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ; 
    }

};

void PrintEntity(const Entity& e)
{
   std::cout << e.GetX() << std::endl;
}

int main()
{
    Entity e; 

    std::cin.get();
}

