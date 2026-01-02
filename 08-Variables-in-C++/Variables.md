Programming is about using data, We manipulate data

Variables allows us to name a piece of data that we store in memory that we keep using it

we create a variable is going to store in one of the two places 
>> the stack or the heap

in c++ we have some primitive data types, which essentially forms the building blocks any kind of data we store in our program 

C++ is very powerfull language , there is very few rules when you get down to it 


the only distinction btw the differnt variable types is 
>>the size, how much memory does this variable occupy 


## syntax
*      int variable = 8
typing the type of the variable giving it some kind of name for example variable and then giving it a value now this last part is optional you don't have to give it a value immediately



1. int 
data type integer
an integer is a data type that is traditionally four byte large the actual size of data type depends on the compiler so it may different depending on the compiler you are using 
ultimately its compiler choice how big your data is going to be

Inps data type is meant for storing integers in a certain range because it's four bytes large we are limited as to what kind of numbers we can store with it specifically this is something called a signed integer that can store a value of around negative two billion to positive 2 billion anything larger or smaller than that is going to require more data to store than this int actually support 


we execute our code 
#include <iostream>

int main()    //int stands for integer
{
    int variable = 8;  //int is signed variable which have range -2B -> 2B

    std::cout<<  variable << std::endl; //intially there was "hello" instead of variable 
    std::cin.get();

}

>> executed successfully


then we done 
two variable
#include <iostream>

int main()    
{
    int variable = 8;  
    std::cout<<  variable << std::endl;

    int variable = 69;
    std::cout<<  variable << std::endl;

    std::cin.get();

}
* error
>>  g++ twovariable.cpp -o twovariable
twovariable.cpp: In function ‘int main()’:
twovariable.cpp:8:9: error: redeclaration of ‘int variable’
    8 |     int variable = 69;
      |         ^~~~~~~~
twovariable.cpp:5:9: note: ‘int variable’ previously declared here
    5 |     int variable = 8;
      |         ^~~~~~~~


error due to two time declaration of int  variable 
we have to declare it only one time like below 

#include <iostream>

int main()    
{
    int variable = 8;  
    std::cout<<  variable << std::endl;

     variable = 69;
    std::cout<<  variable << std::endl;

    std::cin.get();

}

>> executed successfully


## further discussion
as I said an inch data type can store a value between negative 2 billion and positive 2 billion so you might be like why is it billion it's not exactly 2 billion by the way it's like 2 point something billion where are these limits coming from do they make any sense and the answer is yes they make sense they are directly tied with the size of the variable that is how much data were allowed to store in it an integer is 4 bytes with 4 bytes of data we can store values in that let's break

this down a little bit so one byte is eight bits of data which means that four bytes is 32 bits of data because this variable is signed meaning it can be negative it contains a sign like a negative sign because this variable is find one of those bits one of those 32 bits has to be for the sign so that we know if it's positive or negative which only leaves 31 bits left for the actual number now a

bit can either be 0 or 1 so there are 2 possible values for 1 bit of data so using a little bit of maths here we can say that we have 31 bits to play with 2 possible values took bit so what is 2 to the power of 31 if we crack open a calculator here and type in 2 to the power of 31 we will get about 2 billion that value there that 2.1 billion that is the maximum number that we can store with an integer now remember

Technically the max value would be 2,147,483,647 because we also need to store 0

## when don't want signed integer
we also have one bit that is reserved for whether or not that number is negative so because of that we can store up to that number from 0 but also we can go the other way and store all the negative values down to negative 2 by 1 billion but I don't want negative values I hear you say is there a way to just get rid of that one bit being for the negative sign and just use it as part of my number why yes yes there is that is what we call an unsigned number that means it's the number that does not have a sign meaning is always positive in C++ we can make one of those by just typing in unsigned in front of our integer

>> Code we be 
#include <iostream>

int main()    
{
    unsigned int variable = 8;  
    std::cout<<  variable << std::endl;

     variable = 69;
    std::cout<<  variable << std::endl;

    std::cin.get();

}
 
 what we've done is we have 32 bits to play with and 2 to the power of 32 of course is double what we have here for point two nine billion and that's basically what the unsigned keyword does in Sabre slot it lets us define an integer that does not have a sign bit okay

 ## other Data types part 1
>>char
we've got char which is one byte of data 

>> short 
we've got short which is two bytes of data 

>> Int
we have int which is four bytes of data 

>> long 
we have long which is also usually four bytes of data depending on the compiler and

>> long long
 then we have long long which is usually eight bytes of data 
 
 

basic ones are these five 




 
 there's also other types like 
 >>long int
  there are a few different modifications 



* unsign them

you can also add unsigns to any of these and it will remove that sign bit and let you set a larger number 


## char
char is 1 byte (8 bits)
Total values will be 256 as 2^8 = 256
It is treated as a character type, not a number type

Value 24 is stored as a number

But when printed → interpreted as ASCII character


>> char2.cpp
ASCII table:

24 = non-printable control character

So output looks like:

blank

weird symbol

nothing visible

>> ASCII values

0  to  31   → non-printable control characters
32 → space ' '
48–57 → digits 0–9
65–90 → A–Z
97–122 → a–z
123-126 --- some kinda symbols
127         → non-printable (DEL)


if unsigned 
128-255 ------ we get �


>> char4.cpp 
there is error that is character assigning to variable must be inside '  '


>numbers are just characters and if characters are just numbers then why exactly do we have this distinction why do I say that char is specifically used for characters whereas it's really not that is 

because we often as programmers make assumptions about certain data types if I pass in a char and call it something like character 
I usually expect you to actually assign a character to it so a good example of this is if you actually try and print out a char

>> if I change it to be some other type like a short for example and hit f5 you can see that C out no longer treats it like a character it's going to actually print out the numeric value and even if I assign a character here it's just really assigning the value 65 so if I run this again you can see that we get 65


>> so the reason I'm telling you all this is because I want you to understand that data types the usage of data types is just up to the programmer really there are certain conventions that we have in place but there's nothing concrete that you have to actually follow
 there are very little rules and c++ after all so because of that I do want you to realize that the only real difference between these data types is how much memory will be allocated when you create a variable with that data type so with those integer types aside

 ## what if we want to assign decimal values 

  for example five point five how do I do that well for that we have 
  >>two data types 
  
  * float
we have float and 
  
* double
we have double 

* modified version 
there are also some modifies that you can do like long double we're not going to get into those



float is basically a decimal value that we can store that occupies four bytes of data so let's define a variable here such as 5.5 
we're printing out our float variable and compile our file let's hit f5 to run our program and you can see we get 5.5 printed out 


fantastic now you may think that you've defined a float here but 

* you actually haven't you've actually defined a double 

if we go back to visual studio and we hover our mouse over this value you can see that in brackets it says double as 

>> I just mentioned we have two different variables that we can use to store decimal numbers float and double so how do we discern between what a double is and what a float is 

>> the way we do that is by basically appending an F to our float variables it can be lowercase or uppercase doesn't matter but the point is if we have an F you can see that we've actually declared a 

>>flirt so floats are basically four bytes large 
>>and doubles are eight bytes large 


## bool data type
we have one more primitive datatype to play with and that is bool now bool stands for booling
>> and it can either be true or false 
if we try and print it to our console and hit f5 you can see that we'll actually get a numeric value one 
because of course there's no such thing as true or false those are English words computer deal with numbers 

so basically zero means false and anything except zero any other number means true in this case we'll actually get one printing to the console indicating that it is true

 if we change the default and run our program we will get 0 which means false the bool' data type occupies one byte of memory now you

>might be wondering one byte why the bull can either be true or false surely that only takes one bit to represent and 

>> you are correct 

it does take one bit to represent however when we're dealing with addressing memory that is we to retrieve our ball from memory or stored in memory there is no way for us to actually address individual bits we can only address bytes so because of that we can't actually create a variable type that is one bit because we'd need to be able to access it and we can't we can only access by now course

* one thing you could do on the other hand is be really smart about how you store data and store eight all in one bite that's totally okay one bit per bull but you still have that one byte of allocating memory we'll probably talk about advanced fun tricks like that in the future but for now a bull is one byte of memory 


## sizeof operator
so with all this talk of sizes and bytes and how much everything takes how how do we actually know how big a data type is it is dependent on the compiler after all is there somewhere we can check yes 

yes there is there's an operator we have available to us and zip applause called size of so if

we come over here and we print size of bool for example we basically just type in the word size of and then 

>>// not true in our case only inside the brackets allowed
either in brackets or not doesn't really matter although I do prefer to use brackets or parentheses I should say we type 


in our data type header f5 you can see it tells us that a bull is one byte if I replace this with int and hit f5 we have four and if I do something like double and hit f5 we have eight awesome critical stuff so that's

basically all there is to variables or at least the primitive types that I've covered 

there are many different types that you can actually create in C++ and that have already been created for you however they're all custom types that are all based on these primitive types these are the building blocks that we use to define and store any kind of data we could possibly create 


## we can create pointers or refrences

now with any of these primitive data types we also have the ability to turn them into pointers or references pointers can be declared by writing an asterisk next to your type like this 

>bool*

and references by an ampersand next year type 

>bool&

