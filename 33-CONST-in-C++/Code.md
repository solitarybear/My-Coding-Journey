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

int main()
{
    int a =5;
    a = 3;
    //I'm declaring a variable and I'm not going to modify this variable I don't really want it to be a very variable right because the term variable implies that it can change whereas Const stands for constant which means that you're basically declaring a constant instead of a variable something that will not change

    
    const int Max_Age =90;
    Max_Age = 91; //error expression must be a modifiable lvalue

    std::cin.get();
}



# 3 casting away const 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    int* a = new int ;

    *a = 2;

    a = (int*)&Max_Age;
    //this above line means says to compiler Trust me — I know better. Treat this const int as modifiable
    //This is called casting away const.

    // however when we try to change value of const varaible still we can able to change even though we can't able to write to change that value compiler will show error 
    //but via *a = 44;
    //we are able to write to change the value of Max_Age there will be no compiler error 
    //we Bypass the Const 
    // but still the vaule will not change as because as that value is  declared compliree put it in read only memory 


    std::cout<< *a << std::endl;

    std::cin.get();
}



# 4 const to pointer 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    const int* a = new int ; // that "const" means we can't change the contain of that pointer 
    //const int* a is equivalent to int const* a.......both means and act same 

    *a = 2; //showing error over *a

    a = (int*)&Max_Age; // we can notice there is no error as we can change where the pointer is pointing but we can't change the content of pointer a 
    
    std::cout<< *a << std::endl;

    std::cin.get();
}



# 5 similar to #4 but opposite to it 

>main.cpp
#include <iostream>
#include <string>

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    int* const a = new int ; 

    *a = 2; // now we can change the content of the pointer 

    a = (int*)&Max_Age; //error but we can't re-assign the actual pointer itself something else  

    std::cout<< *a << std::endl;

    std::cin.get();
}





# 6 combining 4 and 5
>main.cpp
#include <iostream>
#include <string>

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    const int* const a = new int ; // 

    *a = 2; // here also error

    a = (int*)&Max_Age; //error
    a = nullptr; // error

    std::cout<< *a << std::endl;

    std::cin.get();
}


# 7 Const in methods ...... const in class
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y;

public:
    int GetX() const    //we putting const on the right side of the method name , this only works in a class by the way. This means this method is not going to modify any of the member class so we can't modify any member class member variables 
// we declare this we a const because we want to GET this value
    {
        m_X = 2 ; //error we're not able to do that 
        return m_X;  
    }

    void SetX(int x) // here we didn't declare the value because we have to set here value 
    {
        m_X = x ; // here we can set value to x ;
    }

};

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    const int* const a = new int ; // 

    *a = 2; // here also error

    a = (int*)&Max_Age; //error
    a = nullptr; // error

    std::cout<< *a << std::endl;

    std::cin.get();
}



# 8 const busrter (lame joke )
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int* m_X , m_Y;

public:
    const int* const GetX() const   //we literally put 3 const in a line 1.const -> returing a pointer that can't be modified , 2.const -> contents of the pointer cannot be modify , 3.const -> and the method promises not to modify actuall entity class 
    {
        m_X = 2 ; //error we're not able to do that 
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ;
    }

};

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    const int* const a = new int ; // 

    *a = 2; // here also error

    a = (int*)&Max_Age; //error
    a = nullptr; // error

    std::cout<< *a << std::endl;

    std::cin.get();
}



# 9 some thing off topic and code almost similar to  # 8
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int* m_X , m_Y; //here m_X will become(pointer) int*  but still the m_Y is a integer 
    // if we want everyhting to be a pointer in one line then we have to stick pointer next to each variable like as below 
    // int* m_X , *m_Y

public:
    int  GetX()
    { 
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ; 
    }

};

int main()
{
    const int Max_Age =90; // here we promise This value will never change

    const int* const a = new int ; // 

    *a = 2; // here also error

    a = (int*)&Max_Age; //error
    a = nullptr; // error

    std::cout<< *a << std::endl;

    std::cin.get();
}




# A questioon by cherno or whatever it is 
I'm reverting back to just having a normal get up the question is why why would I want to declare this as Const like I get that I get that it kind of promises not to touch things in this function and maybe if someone else was extending that function they would say okay cool this is not meant to write to the class

int  GetX() const //however does this actually enforce something the answer is yes it does
    { 
        return m_X;  
    }



# 10 simple reasonable function ---> PrintEntity
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 

public:
    int  GetX() const 
    { 
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ; 
    }

};

void PrintEntity(Entity e)  
//this is the simple reasonable function 
//also this (Entity e) will pass the Copy of entity to the GetX() function
{
    std::cout<< e.GetX() << std::endl;  
}

int main()
{
    Entity e;
    
    std::cin.get();
}



# 11 if the fuction was void PrintEntity (const Entity* e) then 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 

public:
    int  GetX() const 
    { 
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ; 
    }

};

void PrintEntity(const Entity* e)  
{
    e = nullptr; 
    // if this was a pointer i can modify kind of what it's pointing towards so I can set it a null pointer and that's fine 
    // but i cannot modify contents of e
    //std::cout<< e.GetX() << std::endl;  
}

int main()
{
    Entity e;
    
    std::cin.get();
}















# 12 Now i want be able to pass this with const reference 
I don't want to copy my entity class because that would potentially be space lobbying in this case it's a base so it probably wouldn't be but in general I don't want to copy I don't want to be copying all my objects because that will be slow especially for something that's read-only so I want to be able to pass it by cross reference now here's the thing if I pass this by constraints it means that this entity is const 


>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 

public:
    int  GetX() const 
    { 
        return m_X;  
    }

    void SetX(int x) 
    {
        m_X = x ; 
    }

};

void PrintEntity(const Entity& e) 
{
    // e= Entity(); 
    
// so by writing Const reference like (const Entity& e) this I have the exact same case I cannot modify the entity I can't reassign it something else --> e = Entity();

//because remember this doesn't work like it does with pointers if you reassign this reference you're actually changing this object not some other object there's no kind of separation between a pointer and the contents of the pointer because with the references you are the contents right that's all you can modify those already referencing you are that entity even though you're a reference  
    
    //std::cout<< e.GetX() << std::endl;  
}

int main()
{
    Entity e;
    
    std::cin.get();
}



# 13 afterwards the 12  this is very important 
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 

public:
    int  GetX() const 
    { 
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

* Explaination in mynotes.md
also after that explaination
.
.
.
that's why sometimes we need to have two like a identical functions one with const and one without const  as in below main.cpp
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    int m_X , m_Y; 

public:
    int  GetX() const 
    { 
        return m_X;  
    }

    int  GetX()  
    { 
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


# 14 what if we want some variables inside a const method to be modifyable 
we can write mutable before that variable to be able to modidy them inside a const method 
shown as below

>main.cpp
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




