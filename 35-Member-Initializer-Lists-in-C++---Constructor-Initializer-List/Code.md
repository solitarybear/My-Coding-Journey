# 1
>main.cpp
#include <iostream>
#include <string>

class Entity 
{
private:
    std::string m_Name;

public:
    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    std::cin.get();
} 

# 2 adding two constructor 
>main.cpp
#include <iostream>
#include <string>

class Entity 
{
private:
    std::string m_Name;

public:
    Entity()
    {
        m_Name = "Unknown";
    }

    Entity(const std::string& name)
    {
        m_Name = name;
    }

    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;
    std::cout<< e0.GetName()<< std::endl;

    Entity e1("SolitaryBear");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}

# 3 second way we can intialize
>main.cpp
#include <iostream>
#include <string>

class Entity 
{
private:
    std::string m_Name;
    int m_Score;
    
    public:
    Entity()
        :m_Score(0) , m_Name ("Unknown") //this is what a member initializer list that comma means intializing another variable
    {
    }

    Entity(const std::string& name)
    : m_Name (name)
    {
    }

    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;
    std::cout<< e0.GetName()<< std::endl;

    Entity e1("SolitaryBear");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}

* error 
because variables in member intializer list must be in same order at the members were defined 

>main.cpp
#include <iostream>
#include <string>

class Entity 
{
private:
    int m_Score;
    std::string m_Name;
    
public:
    Entity()
        :m_Score(0) , m_Name ("Unknown") //in member intializer list whichever variables we are writing they must be in order as members were define 
    {
    }

    Entity(const std::string& name)
    : m_Name (name)
    {
    }

    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;
    std::cout<< e0.GetName()<< std::endl;

    Entity e1("SolitaryBear");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}



# 4 functional difference in member intailizer list  and why we need member intialzer list 
>main.cpp
#include <iostream>
#include <string>

class Example 
{
public:
    Example ()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    Example (int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }

};


class Entity 
{
private:
    std::string m_Name; 
//when we don't write variable in member initializer list then this std::string was contructed twice one with default constructor and then when we intialize inside the constructor as shown in Entity()

    Example m_Example;    
public:
    Entity()
    {
        m_Name = std::string ("Unknown"); //this what actually without using member intializer list do for --> m_Name = "Unknown"  
        m_Example = Example(8);
    }

    Entity(const std::string& name)
    : m_Name (name)
    {
    }

    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;

    std::cin.get();
}


* OutPut:--
            Created Entity!
            Created Entity with 8!

> what we had done is that 
we had created two Entity even though we coded to Create only one Entity 




# 5 solution to not intialize twice ---> using member intializer list 
>main.cpp 
#include <iostream>
#include <string>

class Example 
{
public:
    Example ()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    Example (int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }

};


class Entity 
{
private:
    std::string m_Name; 

    Example m_Example;    
public:
    Entity()
        :m_Example (Example(8))
    {
        m_Name = std::string ("Unknown"); 
    }

    Entity(const std::string& name)
    : m_Name (name)
    {
    }

    const std::string& GetName() const 
    {
        return m_Name;
    }
};

int main()
{
    Entity e0;

    std::cin.get();
}


* Output ---> no error 
                                Created Entity with 8!









#
