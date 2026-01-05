>pass by value     → copy

void Increment(int x);
{
    x++;
} 




>pass by pointer   → address to variable
void Increment(int* x);
{
    (*x)++;
} 


>pass by reference → same variable


void Increment(int& x);
{
    x++;
} 

# 
there is nothing we can do with the reference that we cannot do with the pointer
pointers are like references except they are even more usefull, they're even more powerful

# 
once u declare a reference u cannot  change what it references

int a =5 ;
int b=8;

int& ref = a;
ref =b;

from the answer ref will always alias with a 
and never change alias once made 

so ref =8 that will change value of a =8 

and a result we get a=8 and b=8;
