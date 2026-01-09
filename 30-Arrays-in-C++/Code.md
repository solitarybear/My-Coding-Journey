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

int main()
{
    int example[5]; // created a array of 5 variable (or elements)
    example[0]= 2;  // accessing a array wiht index 0
    example[4]=4;   // accessing the last element of array of the element with index 4

    int a = example[0]; //saving the data in index 0 of an array "example " to variable "a"
    
    example[-1] = 5; // cause memory access violation 
    example[5]= 2;   // cause memory access violation

    std::cout << example[0] << std::endl; // printing specific array element , here we are printin with index 0
    std::cout << example << std::endl;  // this will print the address of the array because this "example" is a pointer type


    std::cin.get();
}

# 3 without for loops we have to go to every indeces and set them manually 
>main.cpp
#include <iostream>

int main()
{
    int example[5]; 
    example[0]= 2;  
    example[1]= 2;  
    example[2]= 2;
    example[3]= 2;
    example[4]= 2;

    std::cin.get();
}

# 4 using for loops 
>main.cpp
#include <iostream>

int main()
{
    int example[5]; 
    
    for (int i = 0 ;i < 5 ; i++)
    example[i] = 2;

    std::cin.get();
}

# 5 
>main.cpp
#include <iostream>

int main()
{
    int example[5]; 
    int* ptr =example;  // no error beacase example is and in pointer 
    
    

    for (int i = 0 ;i < 5 ; i++)
    example[i] = 2;

    example[2]= 5;
    *(ptr + 2) =6;
//I'm just adding values like - - a pointer the number of bytes that is actually going to add it's going to depend on the type so in this case since the pointer is an integer pointer is going to add two times four because four is the size of each integer 

    std::cin.get();
}

# 6 mast modification but similar to previous 
>main.cpp
#include <iostream>

int main()
{
    int example[5]; 
    int* ptr =example;  // no error beacase example is and in pointer 
    
    

    for (int i = 0 ;i < 5 ; i++)
    example[i] = 2;

    example[2]= 5;
    *(int*)((char*)ptr + 8) =6;  // equivalent to *(ptr + 2) = 6;

    std::cin.get();
}
* if I wanted to actually deal with by it either cast this pointer to a data type that is just one by large for example at char and then if I do that I'll have to add on the eight bytes that I talked about since I then want to write in an integer which is 4 bytes not just a single child which is one byte once I actually do the plot 8 I would need to cast this back into an integer pointer and then of course the reference that to get my internship 

# 7 we can also create arrays on the heap
so we'll make another array here I'll call this one another this will be an int pointer and then I'll set it equal to a new instance where decide that I want so let's go with 5 again this code is identical to this code 
however the lifetime of difference and this is created on the stack it will get destroyed when we reach the end curly bracket and we get out of this scope 
>main.cpp
#include <iostream>

int main()
{
    int example[5]; 
//however the lifetime of difference and this is created on the stack it will get destroyed when we reach the end curly bracket and we get out of this scope
    
    for (int i = 0 ;i < 5 ; i++)
    example[i] = 2;



    int* another = new int[5]; //our array we store at heap 
    
    for (int i = 0 ;i < 5 ; i++)
    another[i] = 2;

    delete[] another;

//however it is since it's created on the heap will actually be alive until we destroy it or into our program and 
//so you need to actually delete it using the delete keyword and if this is an array and we allocated using the array operator here 
//so we use the new keyword with the square brackets we need to delete it using the square brackets
    
    std::cin.get();
}

# 8 
>main.cpp
#include <iostream>

int main()
{
class Entity
{
public:

    int example[5];

    Entity ()
    {
        for (int i = 0 ;i < 5 ; i++)
    example[i] = 2;

    }
};

    Entity e; //if we go to memory of our Entity e then we got what we got previously 


    int* another = new int[5]; //our array we store at heap 
    
    for (int i = 0 ;i < 5 ; i++)
    another[i] = 2;

    delete[] another;

    std::cin.get();
}


if I go to the memory address of my entity and hit enter you can see that I've got all my memory right there the memory address of entity actually just in line contains all of my twos all of my daughters

# 9 creating code 8 on the heap
>main.cpp
#include <iostream>

int main()
{
class Entity
{
public:

    int* example = new int[5];

    Entity ()
    {
        for (int i = 0 ;i < 5 ; i++)
        example[i] = 2;

    }
};

    Entity e; 


    delete[] e.example;

    std::cin.get();
}

* if I go back here and I push this over here to be credit on the heat by using a new keyword I'll run that exact same code you can see that if I go to the memory address of my entity I don't see my twos there at all I see this other memory address which of course is this pointer now I can copy this and put it here I'll have to reverse it because at the end Ian nest though this will actually be 0 0-7 d5e and hit enter I get taken to my actual data 

so there's an indirection again what we've actually got the memory address of a week and another memory address to where our actual array is which means that when we want to access this web basically jumping all around our code first to get to the entity then to get to the array all that stuff

* so of course whenever possible you want to create your array on the stack to avoid that because jumping around memory like that is definitely a performance hit

# 10 size of array and count of array 
>main.cpp
#include <iostream>

int main()
{
class Entity
{ 
public:

    int* example = new int[5];

    Entity ()
    {
        //example-> size()//you can't do this c++



        int a[5];  //raw array allocated on stack memory 
        int size = sizeof(a); 
        // 20 =size of array "a" ---> 4(no. of bytes per data type) * 5 (no. of element in the array)
        int count = sizeof(a) / sizeof(int) ; // 5  // only can be used for a stack allocated array 


        int count = sizeof(example) / sizeof(int) ; 
    // = 0 ----(RHS = 4/5 but as,int count it  will give u an integer = 0)
    //sizeof(exmaple) will be 4 , as example is integer pointer 



    


        for (int i = 0 ;i < 5 ; i++)
        example[i] = 2;

    }
};

    Entity e; 


    delete[] e.example;

    std::cin.get();
}


# 11 some more knowledge 
> main.cpp
#include <iostream>

int main()
{
class Entity
{ 
public:
    const int size = 5;
    int example[size];
    //we can there we be eror of size such that a nonstatic member reference must be relative to a specific object
    // because when u  allocate array on stack it has to be a compile time  known constant* 

    Entity ()
    {
        for (int i = 0 ;i < 5 ; i++)
        example[i] = 2;

    }
};

    Entity e; 


    delete[] e.example;

    std::cin.get();
}

# 12 modify # 11
>main.cpp
#include <iostream>


class Entity
{ 
public:
    static const int ExampleSize = 5; // this will helps to works 
    int example[ExampleSize];

    Entity ()
    {
        for (int i = 0 ;i < ExampleSize ; i++)
        example[i] = 2;

    }
};

int main()
{
    Entity e; 

    std::cin.get();
}


# 13 C++ 11 standard array 
>main.cpp
#include <iostream>
#include <array>

class Entity
{ 
public:
    static const int ExampleSize = 5; // this will helps to works 
    int example[ExampleSize];

    std::array < int, 5> another;  // this is C++ 11 standard array  

    Entity ()
    {
        for (int i = 0 ;i < another.size() ; i++) //ofcourse we really so another .size() here 
        example[i] = 2;

    }
};

int main()
{
    Entity e; 

    std::cin.get();
}

