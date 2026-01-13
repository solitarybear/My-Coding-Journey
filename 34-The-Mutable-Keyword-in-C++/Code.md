# 1 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::cin.get();
}

# 2 one application of mutable is in class
>main.cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; 
    //so marking a class member is mutable means that constants inside that class can actually modify that member
public:
    const std::string& GetName() const  
    {
        m_DebugCount++;
        return m_Name;
    }

};

int main()
{
    const Entity e;
    e.GetName();

    std::cin.get();
}



* Alternatives
>main.cpp
#include <iostream>
#include <string>

    int m_DebugCount = 0;  
//we could move this out into some other class or something and that will be totally fine but that's going to be messy because this applies specifically to this functional through this class

class Entity
{
private:
    std::string m_Name;
public:
    const std::string& GetName() const  
    {
        m_DebugCount++;
        return m_Name;
    }

};

int main()
{
    const Entity e;
    e.GetName();

    std::cin.get();
}



# 3 One more use to mutables 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    

    int x = 8 ;
    auto f = []()
    {
        std::cout << "Hello" << std::endl;

    };

    f();// we can call lamdaas by writing this and just specifying any parameters we might have 


    std::cin.get();
}




# 4 now suppose we have to use x in lamdaa 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    

    int x = 8 ;
    auto f = [=]() // & or &x means same dd--> Capturing by reference  OR = or x --> by value
    {
        x++; //i get an error 
        std::cout << x << std::endl;

    };

    f(); 


    std::cin.get();
}



# 5 what we can do in # 4
>main.cpp
#include <iostream>
#include <string>

int main()
{
    

    int x = 8 ;
    auto f = [=]() // & or &x means same dd--> Capturing by reference  OR = or x --> by value
    {
        int y =x ; // assiging a new variable and increment that variable 
        y++;
        std::cout << y << std::endl;

    };

    f(); 


    std::cin.get();
}


# 6 using mutable key words
>main.cpp
#include <iostream>
#include <string>

int main()
{
    

    int x = 8 ;
    auto f = [=]() mutable // due to mutable we can change the value of variable inside this lamdaa
    {
        x++; //what does lamdaa do here is that assign a local variable same as # 5
        std::cout << x << std::endl;

    };

    f(); 
    // now as we captured by value so outside the lamdaa, the variable will be same as before 
    // x will still be 8
    // because inside lamda function the calculation performed was on local variable as we done in #5
    // if we capture by & and the value can be changea 


    std::cin.get();
}


#