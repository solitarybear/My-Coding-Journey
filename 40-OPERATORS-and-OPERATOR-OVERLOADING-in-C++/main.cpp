#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2 (float x, float y)
        :x(x), y(y) {}

    Vector2 Add (const Vector2& other) const  
    {
        return Vector2 (x + other.x, y + other.y);
    }

    Vector2 operator+ (const Vector2& other) const
    {
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const 
    {
        return Vector2(x * other.x , y * other.y); //* is a multiplication operator 

    }

    Vector2 operator* (const Vector2& other) const
    {
        return Multiply(other);
    }    

    bool operator== (const Vector2& other) const
    {
        return x == other.x && y == other.y ;
    } 

    bool operator!= (const Vector2& other) const  //for not equal
    {
        //return !operator==(other); //alternatively 
        return !(*this == other) ;
        
    } 




};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << "," << other.y;
    return stream;
}



int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); 

    Vector2 result1 = position.Add(speed.Multiply(powerup));  
    Vector2 result2 = position + speed * powerup; //now wwe can see this code looks much much better then the above code  


    // if (result1.equals(result2))   // this is what we have to write in java but in c++ we don't ---instead of that we have the option of writing equals equals operator
    if (result1 == result2);
    {
        //so this will works fine 
    }

    std::cout << result2 << std::endl; //we can't do this because 


    std::cin.get();
}