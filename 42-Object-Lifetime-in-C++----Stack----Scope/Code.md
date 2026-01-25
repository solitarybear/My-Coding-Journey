# 1 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::cin.get();
}

# 2
>main.cpp
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

int main()
{
    {
        Entity e;
    }
    std::cin.get();
}

setting breakpoint at line Entity e ;
and seeing result 

# 3
>main.cpp
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

int main()
{
    {
        Entity* e = new Entity();//here parentheses are optional 
    }
    std::cin.get();
}


* Now here when we set break point at Entity* e = new Entity();
after hitting F10 we didn't go the curlybrackets we kinda jump over those curly brackects and went to std::* line 

so Entity is only created not destroyed -------- however OS cleans memory when our application terminate 

# 4 sort of things you might not want to do
>main.cpp
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


int* CreateArray ()
{
    int Array[50];// creating an array 
    return Array ;//returning a pointer to an array (i.e. Array) 
}
//its kinda looking sensible code that - - int Array[50]; is creating an array on the stack then  -- return Array; returning a pointer (Array) to the array its seems legit reight --> WRONG
// but this function written is wrong

int main()
{
    {
        Entity* e = new Entity();//here parentheses are optional 
    }
    std::cin.get();
}

> if i right code like this in the main function 
int * a = CreateArray(); //in the main function -- obviously 
>> it going to fail


this will fails as the array created in the function is created on the stack and as the we are out of the scope stack memory to that Array cleared 



# 5  soultion to #4 
u can create the array on the heap 

>main.cpp
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


int* CreateArray ()
{
    int* Array = new int[50]; //allocating Array on the heap 
    return Array ;               
}


int main()
{
    int* a = CreateArray();

    {  
        Entity* e = new Entity();
    }
    
    
    std::cin.get();
}



# 6 another solution to #4 
* we can asked The data that we have created here to actually copied to a location that exist further up the stack 
>main.cpp
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

void CreateArray (int* Array)
{
    //fill our array
}


int main()
{
    int Array[50]; //created my array over here 

    CreateArray(Array); //  i want CreateArray to be more of a fill an array, which would take in that array and do whatever it want to in the function 

    {  
        Entity* e = new Entity();
    }
    
    
    std::cin.get();
}



# 7 taking leverage to this automatic destruction as we are out of the scope
we can automate the new and delete thing for the heap allocation

>main.cpp
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


* even though we used new Entity(); - - - -  for heap allocation we automatically deleted that heap alloxcation 
as the ScopedPtr is allocated on the stack so when it delete automaticaly we had putted delete heap allocation code in the destructor due to which heap allocation is deleted as we are out of the scope 

>this is all what a very basic smartpointer called  *unique pointer* does 


#

