# 1 
>main.cpp
#include <iostream>

int main()
{
    std::cin.get();
}

# 2

# 3 codes by me
## 1
>main.cpp
#include <iostream>

int main()
{
    const char*  name = "SolitaryBear";
    std::cout<< name <<std::endl;

    char b ;

    std::cout<< sizeof(name) <<std::endl; // 8
    // doesn't print size of string name , name is pointer so prints size of pointer


   // *((char*)name[8]) = b ; //don't run warning // wrong becase see in mynotes.md
    b = name[8]; //assignment to b 

    //name[8] = b; // this would be wrong becase this is assignment to name[8] not possible as name is not modifiable.



    std::cout<< b <<std::endl;
    





    std::cin.get();
}

* explaination in mynotes.md

## 2
>main.cpp
#include <iostream>

int main()
{
     char*  name = "SolitaryBear";
    std::cout<< name <<std::endl;

    char x ;

    std::cout<< sizeof(name) <<std::endl; // 8
    // doesn't print size of string name , name is pointer so prints size of pointer


   // *((char*)name[8]) = b ; //don't run warning // wrong becase see in mynotes.md
    x = name[8]; //assignment to b 

    //name[8] = b; // this would be wrong becase this is assignment to name[8] not possible as name is not modifiable.

    std::cout<< x <<std::endl;

    char* ref = &name[8];

    ref = "b";
    
    std::cout << name << std::endl;


    std::cin.get();
}

* error error 

## 3 correct 
>main.cpp
#include <iostream>

int main()
{
    char  name[] = "SolitaryBear";
    std::cout<< name <<std::endl;

    char x ;

    std::cout<< sizeof(name) <<std::endl; // 8
    // doesn't print size of string name , name is pointer so prints size of pointer


   // *((char*)name[8]) = b ; //don't run warning // wrong becase see in mynotes.md
    x = name[8]; //assignment to b 

    //name[8] = b; // this would be wrong becase this is assignment to name[8] not possible as name is not modifiable.

    std::cout<< x <<std::endl;

    char* ref = &name[8];

    char smallb = 'b';
      *ref=smallb ;
    
    std::cout << name << std::endl;


    std::cin.get();
}

# 4 code by me again 
>main.cpp
#include <iostream>

int main()
{
    const char*  name = "SolitaryBear";
    std::cout<< name <<std::endl;

    name = "thecherno";
    

    std::cout << name << std::endl;


    std::cin.get();
}
* Output 
SolitaryBear
thecherno

now may be u think that the memory where the SolitaryBear was wrttien then after the code 
    name = "thecherno";
it has override on  that SolitaryBear 

instead it provide a new address or we can say now the name point to a different addresss from that it was pointing for "SolitaryBear"

the new address is just after the where SolitaryBear and null character(/0) (Null terminated )


# 5 
I think I'm a not going to initialize it right here I'll set it equal to the individual characters characters and see what works 
by the way I define with a single quote not double quotes 

if it's double quotes then by default it becomes a child pointer okay not a string a child pointer will get into strings in a minute we have  S  o l  i  t  a  r  y  B  e  a  r  
now this is an array not a string right just an array of six characters you can see there's Nord null termination character

>main.cpp // name2 without null terminator or without declaring a null
#include <iostream>

int main()
{
    char*  name = "SolitaryBear";  // character in double quates are define as char point by default .

    char  name2[12] = {'S','o' ,'l', 'i', 't', 'a', 'r', 'y', 'B', 'e', 'a', 'r'}; // new char array 

    std::cout<< name2 <<std::endl;

    name[2]= 'a';


    std::cin.get();
}

>main.cpp with null terminator in array char name 
* name2[13] is an array not string letral
#include <iostream>

int main()
{
    char*  name = "SolitaryBear";  // character in double quates are define as char point by default .

    char  name2[13] = {'S','o' ,'l', 'i', 't', 'a', 'r', 'y', 'B', 'e', 'a', 'r', 0 }; 
    //for null terminator either write 0 or '/0' 

    std::cout<< name2 <<std::endl;

    name[2]= 'a';


    std::cin.get();
}


# 6 Using a Standard string----- std::string
std::string has a constructor that actually takes in a child pointer or a const child pointer
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "SolitaryBear"; //hover your mouse over this you'll see that it is actually a Const char array not a char array

    std::cout<< name <<std::endl;

    std::cin.get();
}





# 7 what if we had commented #include <iostream>
>main.cpp
#include <iostream>
//#include <string>

int main()
{
    std::string name = "SolitaryBear"; 

    std::cout<< name <<std::endl;

    std::cin.get();
}

* error on  <<
we get an error on this output stream operators telling us that we cannot send a string into the center to be our output string because the overload for this operator that allows us to push string in there is inside this header file  #include <string>


# 8 now as this std::string is proper class with  bunch of function 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "SolitaryBear"; 
    //char* s;  // if we had char * s --- string then we have to C functions like below 
    //strlen(s); for length  of string 
    //strcpy; // for copy string 
    name.size(); //define for std::string for finding the length of the string 


    std::cout<< name <<std::endl;

    std::cin.get();
}

# 9  we can't do this 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "SolitaryBear" + "Hello!"; // we can't do this that inside double quoutes are const char array they are not actually a string , actually u can add two or dozen of array together

    std::cout<< name <<std::endl;

    std::cin.get();
}

# 10 what we can actually do is 
you want to do something like this a nice easy way to do that is either with this up into multiple lines because now you're doing name plus equals colors so what you're doing is you're adding a pointer to an actual name which is a string you're adding it to a string 
and plus equal is overloaded in the string class to be able to let you to let you do that
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "SolitaryBear"; //+ "Hello!"; 
    name += "Hello!";
    
    std::cout<< name <<std::endl;

    std::cin.get();
}

* another thing that we can do is that
one thing that I do quite often as well is just threw out one of them with the strings instructor for you explicitly calling a string constructor so you're making a string out it is and then appending that to it as well and that will be totally fine 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 

    std::cout<< name <<std::endl;

    std::cin.get();
}

# 11 what 
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 
    bool contains = name.find("no") != std::string::npos;
    std::cout<< name <<std::endl;

    std::cin.get();
}

# 12 what about passing these strings around other functions 
>main.cpp
#include <iostream>
#include <string>

void PrintString(std::string string) 
// we won't do this because then it's actually a copy we haven't talked about this too much but when you pass in a class like this to a function what you're actually doing is you're creating a brand you're creating a copy of that class of that object and giving it to this function
{
    std::cout << string << std::endl;

}

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 
    bool contains = name.find("no") != std::string::npos;
    std::cout<< name <<std::endl;

    std::cin.get();
}



# 13 why we shouldn't passed our string object directly making a class 
>main.cpp
#include <iostream>
#include <string>

void PrintString(std::string string)
{
    string += "h"; //this changes woundn't affect the original string (name) that was passed in , this changes will make in the copy string named as name 
    std::cout << string << std::endl;

}

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 

    PrintString(name);
    //if we do these this would pass name and then in above function it would make a new class (copy class) of over string , the reason we shouldn't do that is copying means creating a new memory on heap and that is appeerently a slow process 



    bool contains = name.find("no") != std::string::npos;
    std::cout<< name <<std::endl;

    std::cin.get();
} 

# 14 we can do instead 
passing through a const reference 

>main.cpp
#include <iostream>
#include <string>

void PrintString(const std::string& string) //const because we are promissing not to write as string is in ROM, and reference because to not copy 
{
    std::cout << string << std::endl;

}

int main()
{
    std::string name = std::string("SolitaryBear") + "Hello"; 

    PrintString(name);



    bool contains = name.find("no") != std::string::npos;
    std::cout<< name <<std::endl;

    std::cin.get();
}
