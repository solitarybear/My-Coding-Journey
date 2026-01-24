# 1
>main.cpp
#include <iostream>
#include <string>

int main()
{
    std::cin.get();
}



# 2 Example adding to object and getting a another object as a result  
>main.cpp
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

    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    
    //now we have to overload these above vectors together store as result over here (in result object)
    Vector2 result = position.Add(speed); //for this we will define Add function which gonna written a brand new Vector2   

    std::cin.get();
}



* Explaination
Vector2 Add (const Vector2& other) const  
    {
        return Vector2(x + other.x, y + other.y);
    }

we'll quickly define the add function this is going to return a brand new vector2 
we'll call the function add it's going to take in an existing Vector2 (Vector2&) will pass this by constants (const Vector2&) to avoid copying well mark the function as constants (const) it's not going to modify this class 
it's just going to create a new Vector2 with the result and 

we'll just return it back to --- return Vector2 (x + other.x, y + other.y);


# 3 example using multiplication
>main.cpp
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

    Vector2 Multiply(const Vector2& other1) const 
    {
        return Vector2(x * other1.x , y * other1.y); //* is a multiplication operator 

    }

    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); //we want to increase speed slightly faster by increase by 10% 

    //for that we do something like speed multiply powerup
    //now we have to overload these above vectors together store as result over here (in result object)
    Vector2 result = position.Add(speed.Multiply(powerup)); //for this we will define Multiply function along with Add which gonna written a brand new Vector2   

    std::cin.get();
}

>this
is where it starts to look a little bit hard to read and unfortunately in language such as Java this really is your only choice but in C++ we have operator overloading which means that we can take advantage of those operators and actually define our own to deal with the vector to struct so potentially instead of writing something like this we can convert this to just use the mathematical operators


# 4 operator overloading -- 
that is we can take advantage of those operators and actually define our own to deal with the Vector2 struct 
>main.cpp
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

   
    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); 

    Vector2 result1 = position.Add(speed.Multiply(powerup));  
    Vector2 result2 = position + speed ; //* powerup; // using operator overloading //by precedence speed * powerup will get evaluated first  
//we will define these operators as an other funtions 
    std::cin.get();
}





# 5 alternative to 4
I could have basically done the reverse of this instead of this operator calling the add function I could make the add function call the plus operator and a lot of people actually don't know about this because the syntax looks a bit weird and you don't see this very often but what you could do is just change this to be basically that and then over here in add 
>main.cpp
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2 (float x, float y)
        :x(x), y(y) {}

    Vector2 Add (const Vector2& other) const  
    {
        //return *this + other;      //this would kinda easy case 
        
        //we are dereferencing 'this' beacause this is a const pointer to the Vector2 in this Entity so to make it as Vector2 we are dereferencing 'this'
        
        return operator+(other);     //this is the alternate way to return //addressing this operator+ as a function  
    }

    Vector2 operator+ (const Vector2& other) const
    {
    return Vector2 (x + other.x, y + other.y);  
    }

    Vector2 Multiply(const Vector2& other) const 
    {
        return Vector2(x * other.x , y * other.y); //* is a multiplication operator 

    }

   
    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); 

    Vector2 result1 = position.Add(speed.Multiply(powerup));  
    Vector2 result2 = position + speed ; //* powerup; // using operator overloading //by precedence speed * powerup will get evaluated first  
//we will define these operators as an other funtions 
    std::cin.get();
}



* personally TheCherno like the way in code #4



# 6 completing the code #4
>main.cpp
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

   
    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); 

    Vector2 result1 = position.Add(speed.Multiply(powerup));  
    Vector2 result2 = position + speed * powerup; //now wwe can see this code looks much much better then the above code  
    std::cin.get();
}



# 7 left shift kinda operator 
the left shift kind of operator that we use with std::cout 

let say we want to print the Vector2 result2 in the console 
>main.cpp
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

   
    
};

int main()
{
    Vector2 position(4.0f ,4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f); 

    Vector2 result1 = position.Add(speed.Multiply(powerup));  
    Vector2 result2 = position + speed * powerup; //now wwe can see this code looks much much better then the above code  

    std::cout << result2 << std::endl; //we can't do this because 


    std::cin.get();
}

so surprised

look now that we've got this vector two we want to actually print it to the console std::cout as you probably would have noticed has this kind of shift left operator (<<) which takes in various types, at the left side we've got the cout class and of the right side we've got some kind of data types so we'll type and result2 which is that Vector(Vector2) and then we'll we were just able to do this

* we can't

do this because there is no overload for this operator which takes in an output stream which is what cout is and then an actual Vector2 

code we are talking about 

std::cout << result << std::endl; 





but we can add that



# 8 solution to # 7
>main.cpp
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

    std::cout << result2 << std::endl; //we can't do this because 


    std::cin.get();
}




* --
so outside of the vector to a class because there's nothing to do with vector we're just adding this to see out what we're going to do is write STD or a stream which stands for output streams of reference so this is the original kind of definition of this operator that I'm overloading here we're going to write operator left shift inside here we're going to take in the class because you can see this is a definition outside of class so we

still need a reference to the existing stream which in this case is going to be C out and then I'm going to pass my cost vector by reference here over here I'm going to say stream and then shifts basically whatever I want to print so in this case alpha dot X the stream already knows how to print a flirt so we don't need to overload the flirt or anything like that and there may be a comma and then a bird or Y and make sure that you've cost right

finally we need to return a reference to the stream which is just this stream so we can just get returned stream and that's it you consider this code


> ok now this code compiles 


>What is std::ostream
std::ostream is the base class for all output streams in C++.
It represents:

something you can write output to

Examples of std::ostream objects
Object	Meaning
std::cout           	standard output (terminal)
std::cerr	            error output
std::ofstream	        file output
std::ostringstream	    string output

All of these inherit from std::ostream.

So by using std::ostream&, your function works for all of them, not just cout

>Why the parameter is std::ostream& os
std::ostream& stream

Means:
stream is a reference → no copying
refers to the output stream being used

This allows:
std::cout << v;
file << v;

Both work with the same function.

>Why we return std::ostream&
return os;

This is CRITICAL.
It enables chaining:
std::cout << v << std::endl;

Which becomes:
operator<<(operator<<(std::cout, v), std::endl);

If you didn’t return os, this would not compile.



# 9 equals equals operator ----    == operator  
>main.cpp
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




> - - - -
pool because that's a returned resolved cost can return true or false operator equals equals constitu reference other const because it's just a comparison we're not going to be modifying this class and we'll just return x equals equals x and y equals equals other del y so we're

basically checking to see if this floats are exactly the same crawling down here we can change this code to say something like result equals equals resolved to i can see that works have a big fan and finally if we wanted a not equals operator we with a copy this code change this to not equals and then just call basically the opposite of equals so we'll call this equals equals other but we'll put this in parenthesis with an exclamation mark at the front to reverse the result of that alternatively with the kind of syntax that I showed you earlier you could write something like return operator equals equals other and then kind of reverse that result and return that that looks weird don't do it that way if you are doing it this way which you probably should pretend this well maybe alternatively just have an equals function and call pad and return the reverse of that or something like that 


#
