#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity() //constructor without parameter
    {
       
    }

    Entity(float x, float y)   //Constructor with parameters
    {
        X=x;
        Y=y;

    }

    void print()
    {
        std::cout << X <<","<< Y <<std::endl;
    }
};

class Log
{

public:

       Log() = delete ; //so we deleted our default constructor
        static void write() 
        {

        }

};

int main()
{
    Log::write();
    Log l; // as we deleted the constructor so now new instances not able to intialized as result no instances will be created.


    Entity e(10.0f, 5.0f);                          // now have the option of constructing entity with parameters
    e.print();

    std::cin.get();
}