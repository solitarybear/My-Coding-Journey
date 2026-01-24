# 1
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::cin.get();
}


# 2  I want to do is assign these fields these member variables(x,y) with the values of these parameters (x,y)
what I want to do is assign these fields these member variables with the values of these parameters of course I could use and initialize a list and just do this and that will be totally fine
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
        :x(x) , y(y)      //we can do through initializer list  
    {

    }
};

int main()
{
    std::cin.get();
}



# 3 what if we want to what is in #2 in the body then
however if I didn't want to do that and I wanted to actually do it in the body I would be faced with a little bit of a problem 
because as you can probably notice they have exactly the same name so if I try and do x equals x I'm actually just assigning this X variable the parameter with its own value which is just doing absolutely nothing 


* what I really want to do is reference the X and y that belongs to the class the actual class members and that's what the this keyword actually allows me to do


>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {
        x = x ;//I'm actually just assigning this X variable the parameter with its own value which is just doing absolutely nothing
        y = y ;

    }
};

int main()
{
    std::cin.get();
}

# 4 Understanding the 'this' keyword
I mentioned the keyword is basically a pointer to the current instance so to make this a little bit more clear I'm just gonna write it out here entity point so I'll just call it a and I'll assign it to this that is the type of this technically 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {
        Entity* e = this; //as we mentioned that 'this' is pointer to the current instance 
        //Entity* is the type of this  
    }
};

int main()
{
    std::cin.get();
}


* more acknowledgment 
>if you hover your mouse over you'll see that it's actually an Entity pointer constant so you could set it to that if you want to

----   Entity* const e = this;
----   this = nullptr;         //we could not assign this to something else 

however most people don't most people just assign it to an entity pointer because what Const means on the right-hand side of this is that when I'll allow to reassign this to something else so we

couldn't write this equals null pointer for example or attempt to actually assign this to a reference here that is non constant this sense we would actually have to declare this as Const like that 

>we would actually have to declare this as Const like that

------  Entity* const e = this;

>or attempt to actually assign this to a reference here that is non constant 
-----   Entity*& const e =this;  //we can't do this too

>this sense we would actually have to declare this as Const like that

-----   Entity* const & e = this;






# 5 if we now want to assign x we would do is 
if we now want to actually assign X we can just do a arrow X and just assign X or of course to make this a little bit more simple we can just do this arrow x equals x

>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {
        Entity* e = this; //equivalent to Entity* const e = this;
        
        this->x = x; //equivalent to e->x = x ;
    }
};

int main()
{
    std::cin.get();
}


* we can also do this 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; 
    }
};

int main()
{
    std::cin.get();
}



# 6 alternatively we can write the code like this 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        (*this).x = x; //but obvioosly that looks clean with the arrow so we use that 
        //e->x is the same as (*e).x //This is a language rule, not a coincidence.
    }
};

int main()
{
    std::cin.get();
}

# 7 completing the above code 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;
    }
};

int main()
{
    std::cin.get();
}

# 8 if we were write a function which return these variables   
then that is pretty much comman to us to mark as const as below
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;
    }

    int GetX() const //marking this as const is pretty much common //means we are not goint to change member of this class 
    {
        Entity* e = this; //in  a const function 'this' isn't actually equal to an Entity*
        //because Entity* e means e is non-const pointer to an Entity and copy of 'this' (const pointer to Entity)
        //that means we can change the value of the address e pointing to which is not allowed as member function marked as const
        
        return x;
    }
};

int main()
{
    std::cin.get();
}

* error

# 9 no error to #8
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;
    }

    int GetX() const //because we are putting const here 

    {
        const Entity* e = this; //this' is equal to a const Entity*
        //because we are putting const here 
        return x;
    }
};

int main()
{
    std::cin.get();
}


# 10 another usefull case for the 'this' 
>main.cpp
#include <iostream>
#include <string>

void PrintEntity(Entity* e);

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;

        PrintEntity(); //what should we pass if we want to call the function outside the class with the current instance ?? answer is 'this'  
    }

    int GetX() const //marking this as const is pretty much common
    {
        const Entity* e = this; //'this' is equal to a const Entity*
        return x;
    }
};

void PrintEntity(Entity* e)
{
    //wanna do some printing kinda stuff
}

int main()
{
    std::cin.get();
}


>another useful

case for this is if we maybe wanted to call a function that was outside of this entity class so it wasn't a method but we wanted to call a function outside this class from within this class that took entity as a parameter so as an example maybe we had a print entity function and because of the declaration water here I'm actually going to have to declare this up here and then define it over here so we have

a function that might do some cool printing kind of stuff and we want to be able to cooperate to entity from inside this class so it may be like this
I want to pass in the current instance of this entity class into this function how do I do that that's where this comes in 
I can just pass him 'this' and that's going to


>why did cherno wrote the declaration above the class and the definition below the class 
The key rule (this is the reason)

In C++, a function must be declared before it is used.

Not defined — declared.

>Why only the declaration is enough

This line:

void PrintEntity(Entity* e);


Tells the compiler:

the function exists

its name

its parameter types

its return type

That’s all the compiler needs to allow the call.

The actual body can come later.

>Why definition is written AFTER the class

Because:

The function uses Entity*

The compiler needs to know what Entity is

That requires the class to be fully defined

So this would be impossible:

void PrintEntity(Entity* e)
{
    // uses Entity members
}


before the class definition.



# 11 what we can do in the #10 is 
>main.cpp
#include <iostream>
#include <string>

void PrintEntity(Entity* e);

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;

        PrintEntity(this);
    }

    int GetX() const //marking this as const is pretty much common
    {
        const Entity* e = this; //this' is equal to a const Entity*
        return x;
    }
};

void PrintEntity(Entity* e)
{
    //wanna do some printing kinda stuff
}

int main()
{
    std::cin.get();
}


>of course passing the current instance with the X&Y that I've got set here if I wanted to take this in as a constant reference all I would have to do here is actually just dereference it and there we go so of

course would be referencing this in the case of a non concert we'll just get an entity reference back like so and then a Const method we would get a Const reference back like so


# 12 some changes in the code #11
>main.cpp
#include <iostream>
#include <string>

void PrintEntity(const Entity& e);

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;



        PrintEntity(*this); //so we are derefencing here
    }

    int GetX() const //marking this as const is pretty much common
    {
        const Entity* e = this; //this' is equal to a const Entity*
        return x;
    }
};

void PrintEntity(Entity* e)
{
    //wanna do some printing kinda stuff
}

int main()
{
    std::cin.get();
}


* the changes are 
we changed the parameter of the function PrintEntity from Entity*  to const Entity& 
that means not we are taking an Entity Object inside the function 

so for calling the function outside the class within the class with the current instance then we we want to call we the current object that we can do by writing 
PrintEntity(*this);



# 13 
>main.cpp
#include <iostream>
#include <string>

void PrintEntity(const Entity& e);

class Entity
{
private:
    int x, y;

public:

    Entity(int x, int y)
    {       
        this->x = x; //but obvioosly that looks clean with the arrow so we use that 
        this->y = y;

        Entity& e =*this; //in case non const method we will get entity reference back

        PrintEntity(*this); //so we are derefencing here\

       // delete this; //we can also do this //recommendation to avoid this  
    }

    int GetX() const //marking this as const is pretty much common
    {
        const Entity& e = *this; //so in a const method we  would get const refenerce back
        return x;
    }
};

void PrintEntity(Entity* e)
{
    //wanna do some printing kinda stuff
}

int main()
{
    std::cin.get();
}

* the delete keyword we commented 
>because this is a pointer to the current class we can also do some pretty bizarre things such as called delete this I've seen this code a handful of times in very very specialized cases my recommendation would be of course to avoid doing this 

because you're freeing memory from a member function and if you decide to ever access any member data after you call delete this you're going to explode because the memory had been freed so don't

don't don't typically write code like this just make this is C++ there's kind of a there's a place for pretty much everything but but don't, 
maybe 
no don't 

---------------------------------------------------------------------------------- 

* now cherno is stating we the new two lines is simple 
in non const method 
*this - - - - is - - - - - -  Entity& e

and in const method 
*this - - - - is - - - - - -  const Entity& e 

#

