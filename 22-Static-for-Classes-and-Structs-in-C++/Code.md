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

struct Entity
{
    int x ,y ;

    void Print()
    {
        std::cout<< x <<"," << y << std::endl;
    }
};

int main()
{
    Entity e1;
    e1.x=69;
    e1.y=70;

    Entity e2={24,25};

    e1.Print();
    e2.Print();

    std::cin.get();
}

* Output --- 
69,70
24,25

# 3 static variable inside a class
>main.cpp
#include <iostream>

struct Entity
{
    static int x ,y ;

    void Print()
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

    e1.Print();
    e2.Print();

    std::cin.get();
}

* Error

# 4 static vriable inside class with no error
>main.cpp
#include <iostream>

struct Entity
{
    static int x ,y ;

    void Print()
    {
        std::cout<< x <<"," << y << std::endl;
    }
};

// 🔑 static member definitions (REQUIRED)
int Entity::x = 0;
int Entity::y = 0;

int main()
{
    Entity e1;
    Entity::x=69;  //e1.x=69;
    Entity::y =70; //e1.y=70;

    Entity e2;
    Entity::x=24; // no need to write e2 , Even this e2.x=24; is also correct
    Entity::y = 25;//e2.y=25;

    e1.Print();
    e2.Print();

    std::cin.get();
}

* Output 
24,25
24,25

# 5 static method inside class
>main.cpp
#include <iostream>

struct Entity
{
    static int x ,y ;

    static void Print()         // it would be fine just typing static because  inside the method x , y are also static variable.
    {
        std::cout<< x <<"," << y << std::endl;
    }
};

// 🔑 static member definitions (REQUIRED)
int Entity::x = 0;
int Entity::y = 0;

int main()
{
    ///Entity e1; we don't even need this class instances at all
    Entity::x=69;  //e1.x=69;
    Entity::y =70; //e1.y=70;

    //Entity e2;   we don't even need this class instances at all
    Entity::x=24; // no need to write e2 , Even this e2.x=24; is also correct
    Entity::y = 25;//e2.y=25;

    Entity print();      //e1.Print();
    Entity print();      //e2.Print();

    std::cin.get();
}

# 6 static methods cannot access non-static variables
>main.cpp
#include <iostream>

struct Entity
{
      int x ,y ;

    static void Print()         // it would be fine just typing static because  inside the method x , y are also static variable.
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

* Error
you can see our error reads illegal reference to non-static member entity X because you cannot access this from a static method the reason is that a static method does not have a class instance 

# 7
>main.cpp
#include <iostream>

struct Entity
{
      int x ,y ;

    static void Print()        
    {
        std::cout<< x <<"," << y << std::endl;
    }
};

static void Print(Entity e)        
    {
        std::cout<< e.x <<"," << e.y << std::endl;  
    }                                             //suddenly this works
// we've just written here this method that we've just written here is essentially what a class method that is non-static actually looks like when it's compiled
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