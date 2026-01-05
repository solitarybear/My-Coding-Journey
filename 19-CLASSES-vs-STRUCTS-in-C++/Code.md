# 1
>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

class Player     
{
public:
    int x, y;     
    int speed;

void Move( int xa, int ya) 
    {
           x += xa * speed; 
           y += ya * speed;
    }
};


int main()
{
    Player player; 
    player.Move( 1, -1);
    player.x = 5;
    std::cin.get();
}


# 2 class ---> struct

<Technically the only difference btw the class and struct is about default visibility
default visibility -----class---> private
                        struct--> public

>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

struct Player     
{

    int x, y;     
    int speed;

void Move( int xa, int ya) 
    {
           x += xa * speed; 
           y += ya * speed;
    }
};


int main()
{
    Player player; 
    player.Move( 1, -1);
    player.x = 5;
    std::cin.get();
}

# 3 how we might difine difference btw struct and class 
*  we might be defining differences between those two words because Like they might not technically have much of a difference

however the usage in code is actually going to differ 

>the only reason struct really even exists in C++ Is because of the backwards compatibility that it wants to maintain with C, because code doesn't have classes It does have structures though, and if we were suddenly to wipe out this whole struct Keyword Entirely then we would lose all compatibility because The compilers the C++ compiler wouldn't know what struct was of course you could fix that pretty easily by just using a hash to find

>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl
#define struct class
struct Player     
{

    int x, y;     
    int speed;

void Move( int xa, int ya) 
    {
           x += xa * speed; 
           y += ya * speed;
    }
};


int main()
{
    Player player; 
    player.Move( 1, -1);
    player.x = 5;
    std::cin.get();
}

# 4 when do i use struct vs class 
>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl

struct Player     
{

    int x, y;     
    int speed;

void Move( int xa, int ya) 
    {
           x += xa * speed; 
           y += ya * speed;
    }
};

struct vec2
{
    float x ,y;

    void add(const vec2& other )
    {
        x+= other.x;
        y+= other.y;
    }
};

int main()
{
    Player player; 
    player.Move( 1, -1);
    player.x = 5;
    std::cin.get();
}



