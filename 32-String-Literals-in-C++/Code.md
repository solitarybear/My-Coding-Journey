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
    "SolitaryBear"; //string leteral
    // if hovwer over above string literal then we see const char [13], that extra 1 is for null terminator can  be wriiten as below and denoted as 0 in numerical meaning 

    //"SolitaryBear/0";

    std::cin.get();
}



# 3
>main.cpp
#include <iostream>
#include <string>

int main()
{
    "Solitary\0Bear"; //by puting that \0 in middle of the string we had break the behavviour of string in many cases 


    std::cin.get();
}



# 4
>main.cpp
#include <iostream>
#include <string>

#include <stdlib.h> //includes some c functions 
#include <cstring>  //cherno not incuded this because he is using MSVS microsoft visual studios with helps sideways including many other thing 

int main()
{
    const char name[14]  = "Solitary\0Bear"; 

    std::cout<< strlen(name) <<std::endl; //strlen -- C function which tells me how long is mine string is 


    std::cin.get();
}

* output  8
 that was due to compiler provide size til a first zero 


# 5
>main.cpp
#include <iostream>
#include <string>

#include <stdlib.h> 
#include <cstring>  
int main()
{
    char* name  = "SolitaryBear";  // still its a const char* --- and this "SolitaryBear" does store in const section of our binary
    name [2] = 'a';  
    
    std::cout<< strlen(name) <<std::endl; 

    std::cin.get();
}
 // we run this complete code and run its executable files then we get an output as Segmentation fault (core dumped)
 //which means Your program tried to access memory that it is not allowed to access.
 //

* if somehow we want to execute that line of code 
name [2] = 'a';
then "SolitaryBear" must be an array such that 
char name[]  = "SolitaryBear";


# 6 types in char 
>main.cpp
#include <iostream>
#include <string>

#include <stdlib.h> 
#include <cstring>  

int main()
{
    const char* name  = "SolitaryBear";   //const char* also define as u8 prefix such that u8"SolitaryBear" 
    // this as  utf 8


    const wchar_t* name2 = L"SolitaryBear" ;
    //2 bytes per char on windows and 4 bytes on linux and mac 
    


    const char16_t* name3 = u"SolitaryBear"; // this was made to adhere utf -16
    const char32_t* name4 = U"SolitaryBear";// 32 bits character string  having 32bits = 4 bytes per character 
    // this was made to adhere utf 32 

    std::cout<< strlen(name) <<std::endl; 

    std::cin.get();
}



# 7 wierd thing to prepare to strings
>main.cpp
#include <iostream>
#include <string>

#include <stdlib.h> 
#include <cstring>  

int main()
{
    using namespace std::string_literals; //introduce in C++ 14

    //std::string name0 = "Solitary" + "Bear" ; // we can do this because these are string lierals which is ofcourse  arrays or ponters so we can't just add to pointers together
    //std::string name0 = std::string("Solitary") +"Bear" ;//cherno's previous solution for above issue 
    
    std::string name0 = "Solitary"s + "Bear"s ; // this adding s right to the left string literal makes it easier to add to string literal 
    // that s is actually is a  operator function  as below 
    //  inline std::string std::literals::string_literals::operator ""s(const char *__str, std::size_t __len)
    

    // we can also do such as 
    //std::string name0 = u8"Solitary"s + u8"Bear";
    //std::wstring name0 = L"Solitary"s + L"Bear";

    //std::u32string name0 = U"Solitary"s + U"Bear";

    
    //another thing we can know is 'R' keyword 
    const char* example = R"(line1  
    line2
    line3
    line4)";// R stands for row this 'R' keyword  is used to when we want to write paragraph 

    //alternate and less clean then 'R' keyword
    const char* ex = "line1\n"
    "line2\n"
    "line3\n"
    "line4\n";




    const char* name  = "SolitaryBear";   
    const wchar_t* name2 = L"SolitaryBear" ;

    const char16_t* name3 = u"SolitaryBear"; 
    const char32_t* name4 = U"SolitaryBear";
    std::cout<< strlen(name) <<std::endl; 

    std::cin.get();
}






# 8
>main.com

#
#
#
#
#
#