# 1
>main.cpp
#include <iostream>
#include <string>

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
};


int main()
{
    std::cin.get();
}



# 2 smart pointers ------ unique pointers 
>main.cpp
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
        std::unique_ptr <Entity> entity(new Entity()); //we can write like this std::unique_ptr <Entity> entity = new Entity();
        //because when look to the unique ptr then the constructor is Explicit not implicit so we must have to call constructor exlicitly as entity(new Entity ()); 

        //format - - -  std::unique_ptr < template_argument> name(call the costructor);

        entity-> Print(); //if we want to call a methon then we will use a arrow(->) operator

    }


    std::cin.get();
}


# 3 the prefered way  to the code #2
the prefered way to construct a object using unique pointer is to assign it to

* std::unique_ptr <Entity> entity = std::make_unique <Entity>();
because it is slightly safer if the constructions happen thrown to execption

>main.cpp
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
        std::unique_ptr <Entity> entity = std::make_unique <Entity>();

        entity-> Print(); 

    }


    std::cin.get();
}







# 4 the problem with the smart pointer 
>main.cpp
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
        std::unique_ptr <Entity> entity = std::make_unique <Entity>();
        std::unique_ptr <Entity>  e0 = entity;        //there it shows an error 

        entity-> Print(); 

    }


    std::cin.get();
}


* error
function "std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp> &) [with _Tp=Entity, _Dp=std::default_delete<Entity>]" (declared at line 522 of "/usr/include/c++/13/bits/unique_ptr.h") cannot be referenced -- it is a deleted functionC/C++(1776)
std::unique_ptr<Entity> entity

in short 
>We can't copy the unique pointer as we can see in the definition of unique pointer by clicking on go to definition while right clicking on the unique_ptr 

      // Disable copy from lvalue.
      unique_ptr(const unique_ptr&) = delete;
      unique_ptr& operator=(const unique_ptr&) = delete;

this is what written in below inside the definition of unique ptr 

here we can see that copy constructor and copy assignment operator are actually deleted means forbidden to use 


so the problem with this pointer --> unique ptr is when we want to share this ptr or copy this pointer. You can run into a problem because to can't copy that 




# 5 shared pointer 
if u like sharing that's where shared pointer comes in
shared pointer kinda works differently , more hardcore if you will becoz there is lot of other stuff under the hood the way that a shared pointer is implemented is actually kind of up to the compiler and the standard library that you're using with your compiler however in pretty much all systems that I've seen it's it's using something called reference counting


>main.cpp
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
        std::shared_ptr <Entity> e0;
        {
            std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity>();
           //std::shared_ptr <Entity> sharedEntity(new Entity()); //we can also do this but in the case of unique_ptr this new keyword way is not prefered
           //and you definetly don't want to do that for the shared_ptr reason given below
            
           e0 = sharedEntity;
        }

    }


    std::cin.get();
}


* when all the references dies then the heap allocation memory destroyed 
here we set breakpoint at the line std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity> ();

then we can see even though after out the first curly bracket still there isn't priinted that Destroyed but when we come out of second bracket at that time Destroyed Entity is printed because 

after first curly bracket still there is one reference left that was present in next curly bracket annd after that curly bracket Entity is Destroyed 

> in this case you could have also done a new entity like this and you can see if that compiles fine except you definitely don't want to do that with shared pointer with unique points are really the only reason not to call new directly is because of exception safety built with shared pointer there's actually going to be a difference because shared pointer has to allocate another block of memory called the control block where it stores that reference count and if you create if you first created

a new entity and then pass it into the shared pointer constructor it has to allocate that's test2 allocation that's right because you constructing the entity first and then be shared pointer has the controller cut it has to construct its control block whereas if you do make share it can actually construct them together which is a lot more efficient and also for those of you people who hate new and delete this obviously gets rid of the new keyword from your codebase because you're just calling a city make shared instead of new entity





# 6 Weak pinter ----something else we can use with the sharedpointer 
>main.cpp
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
        std::shared_ptr <Entity> e0;
        {
            std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity>();
            std::weak_ptr <Entity> weakEntity = sharedEntity; //there will be copy of shared pointer but doen't increase in reference count as happen usually 
            e0 = sharedEntity;
        }

    }


    std::cin.get();
}

* more theory and knowledge from video lecture or videonotes 




# 7 weak poinnter doen't keep it alive 
weak poinnter doen't keep it alive 
as when when we copy and use shared pointer they keep it alive 
>main.cpp
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
        std::weak_ptr <Entity> e0; // by setting breakpoinnt similar to #5 in this case after 1st curly bracket Entity is Destroyed 
        {
            std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity>();
            std::weak_ptr <Entity> weakEntity = sharedEntity; //there will be copy of shared pointer but doen't increase in reference count as happen usually 
            e0 = sharedEntity;
        }

    }


    std::cin.get();
}



#
#