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
