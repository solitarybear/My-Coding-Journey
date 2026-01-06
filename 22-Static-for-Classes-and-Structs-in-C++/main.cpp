#include <iostream>

struct Entity
{
      int x ,y ;

    static void Print()        
    {
        std::cout<< x <<"," << y << std::endl;
    }
};

int main()
{
    Entity e1;
    e1.x=69;
    e1.y=70;
    

    Entity e2; 
    e2.x=24; 
    e2.y=25;

    Entity print();     
    Entity print();     

    std::cin.get();
}