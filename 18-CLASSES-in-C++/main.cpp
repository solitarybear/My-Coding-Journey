#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

class Player     
{
public:
    int x, y;     
    int speed;

void Move( int xa, int ya) //functions inside a class are called methods
    {
           x += xa * speed; //we have access to these variables we don't need to pass a player object // player.x---> x
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
