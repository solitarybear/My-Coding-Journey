# 1 
>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

int main()
{
    std::cin.get();
}

# 2
>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

int main()
{
    int PlayerX0, PlayerY0;
    int PlayerSpeed = 2;

    
    int PlayerX1, PlayerY1;
    int PlayerSpeed = 2;
    
    std::cin.get();
}

instead of this you could of course use an array but 
>the point is still the same it's just kind of a bunch of variables that aren't grouped together 
they're just unorganized they're just sitting in our code and it's just not a good idea 

# 3 
* another great example of why this is annoying is because if I want to write a function that moves the player or something like that 

* I suddenly need to be specifying all three parameters as integers so for for example the x coordinate the y coordinate the speed 

all of this just becomes so much code and so difficult to maintain and follow that it's just it's really really messy

>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

void Move(int x, int y, int speed);

int main()
{
    int PlayerX0, PlayerY0;
    int PlayerSpeed = 2;

    
    int PlayerX1, PlayerY1;
    int PlayerSpeed = 2;

    std::cin.get();
}
 
# 4 creating  a Class
* so what we can do instead is simplify this by using a class we can create a class for the player

>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

class Player      // here the Player written is a "type" of class and it should be unique
{
public:
    int x, y;     // these inside the curly brackets are definition of type "Player" 
    int speed;

};
int main()
{
    Player player;  // now "Player" "player" are just like ----> "type" "variable".// so we created a new variable called player 

    player.x = 5; 
    //variables that are made from class types are called objects and a new object variable is called an instance
    // "player" is our object and "player " is also intance as we created a new instance
    std::cin.get();
}

# 5 suppose that we actually want our player to do something for example <move
>main.cpp
#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

class Player     
{
public:
    int x, y;     
    int speed;

};

void Move(Player& player, int xa, int ya) 
{
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}

int main()
{
    Player player; 
    Move (player, 1, -1);
    player.x = 5;
    std::cin.get();
}


# 6 classes can actually contain functionality
>main.cpp
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
>this isn't really any different to having the move function outside of the player class all it does is it kind of cleans up our code and makes everything look a little bit nicer and that's a huge bonus when you're dealing with a lot of code because the more code you have the more complicated it can get and the harder it can actually become to maintain that code 
