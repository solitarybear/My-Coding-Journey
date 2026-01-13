# 1 
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 1 ;
static int s_Speed = 2 ;

int main()
{
    std::cin.get();
}


# 2 simple if else statment 
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 1 ;
static int s_Speed = 2 ;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;

    else 
        s_Speed = 5; 
        
    std::cin.get();
}




# 3 using ternary operator 
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 1 ;
static int s_Speed = 2 ;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;

    else 
        s_Speed = 5; 

    s_Speed = s_Level >5 ? 10 : 5; //this is how ternary operator works ---  ? ___answer if true ___ : ___answer if false ___;

    std::cin.get();
}



# 4 another example of ternary operator and differnciating with if else statement 
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 1 ;
static int s_Speed = 2 ;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;

    else 
        s_Speed = 5; 

    s_Speed = s_Level >5 ? 10 : 5;

    std::string rank = s_Level > 10 ? "Master" : "Beginner"; // the reason that this (code) doesn't actually construct an intemediate string is actually has to do with return value optimization. 

    std::string otherRank; //in this case (if and else case) where 'otherRank' is declared there it constructing empty string object 
    if (s_Level > 10)
        otherRank ="Master"; //Then overriding that string object over new one 

    else 
        otherRank = "Beginner";
//this above if else statement code will be different from the above ternary operator code and technically slow because it is creating a temporary string and deleting it imidiately

    std::cin.get();
}





# 5 more example extening the concept and power of ternary operator //we can nesst these ternary operator 
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 1 ;
static int s_Speed = 2 ;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;

    else 
        s_Speed = 5; 

    s_Speed = s_Level >5 ? s_Level > 10 ? 15 :10 : 5; //extending the using ternary operator
    std::cout << s_Speed << std::endl;

    std::cin.get();
}

* put this code on ai and tell to explain what does it means you might be wrong about what you are suppose to mean by this above code 


# 6 something more interesting -- I Bet you u didn't know this (meme u might know (naughty eye emoji))
>main.cpp
#include <iostream>
#include <string>

static int s_Level = 8 ;
static int s_Speed = 2 ;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;

    else 
        s_Speed = 5; 

    s_Speed = s_Level >5 && s_Level < 100 ? s_Level > 10 ? 15 :10 : 5; // nested code 
    
    std::cout << s_Speed << std::endl;

    std::cin.get();
}


* No error in Output 

* even if write code like this 
>s_Speed = (s_Level >5 && s_Level < 100) ? s_Level > 10 ? 15 :10 : 5;
 
still the output would be same that is 10 


cherno video explanation --- better to watch video again
the code 
* s_Speed = s_Level >5 && s_Level < 100 ? s_Level > 10 ? 15 :10 : 5;

how does this code will be treated 
for example like this 
1.                    s_Speed = s_Level >5 && (s_Level < 100) ? s_Level > 10 ? 15 :10 : 5;

OR
would have extend with an AND (&& operator)
2.                    s_Speed = (s_Level >5  &&  s_Level < 100)  ?  s_Level > 10 ? 15 :10 : 5;


so the answer is this statement-------   s_Level >5 && s_Level < 100 ? s_Level > 10 ? 15 :10 : 5;


will be treated like of the stuff like AND --Logical and operator (&&)

like this     -----    (s_Level >5 && s_Level < 100) this is linked as one statement 


# cherno thought 
when the code is not nested then this ternary operator look very beutiful ~TheCherno 
but when nested or code just like 6 try not to like this yaa this is pretty much far (i personally never nest my ternary operator ~ TheCherno)
