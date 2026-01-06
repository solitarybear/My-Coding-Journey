# 1 
>main.cpp
#include <iostream>

int main()
{
    std::cin.get();
}

# 2
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    void print()
    {
        std::cout << X <<","<< Y <<std::endl;
    }
};

int main()
{
    Entity e;
    e.print();

    std::cin.get();
}

* Output
-9.39746e+33,4.59163e-41
some garbage value which was left in the memory

# 3
#include <iostream>

class Entity
{
public:
    float X, Y;

    void print()
    {
        std::cout << X <<","<< Y <<std::endl;
    }
};

int main()
{
    Entity e;
    std::cout<< e.X <<std::endl;
    e.print();

    std::cin.get();
}

in my case there is no error 

>but when the cherno runs the code he got an error as 
 unintialised local variable e is used

* we've already got a need for some kind of initialization we need a way to to every time we construct an entity we want to be able to set X and Y to zero unless we've specified some value

# 4
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    void Init()
    {//create a method called init it'll just be void and it will just take the job of setting X and Y to zero
        X = 0.0f;
        Y = 0.0f;
    }

    void print()
    {
        std::cout << X <<","<< Y <<std::endl;
    }
};

int main()
{
    Entity e;
    e.Init();
    std::cout<< e.X <<std::endl;
    e.print();

    Entity e1;
    e1.Init();

    std::cin.get();
}




* however this is quite a bit of code that we've written extra we've had to Define this init method and every time we want to create an entity in our code 


# 5 using Constructor
>main.cpp
#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity() //constructor without parameter
    {
        X=0.0f;
        Y=0.0f;
    }

    void print()
    {
        std::cout << X <<","<< Y <<std::endl;
    }
};

int main()
{
    Entity e;
    std::cout<< e.X <<std::endl;
    e.print();

    std::cin.get();
}
 
 
# 6 Constructor with parameter
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

int main()
{
    Entity e(10.0f, 5.0f);                          // now have the option of constructing entity with parameters
    e.print();

    std::cin.get();
}

# 7 Privating the default constructor so not to able to create new instance 
* when you use the new keyword and create an object instance it will also call The Constructor
>main.cpp
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
private:
Log() {}               // first method making the constructor private 
public:
        static void write() 
        {

        }

};

int main()
{
    Log::write();
    Log l;


    Entity e(10.0f, 5.0f);                          // now have the option of constructing entity with parameters
    e.print();

    std::cin.get();
}

# 8 deleting the default construtor to not allow to create instance
>main.cpp
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
    Log l;
// as we deleted the constructor so now new instances not able to intialized as result no instances will be created.


    Entity e(10.0f, 5.0f);                          // now have the option of constructing entity with parameters
    e.print();

    std::cin.get();
}