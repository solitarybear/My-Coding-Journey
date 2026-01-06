# 1
>main.cpp
#include <iostream>

int main()
{
    std::cin.get();
}

>static.cpp



# 2 
>main.cpp
#include <iostream>

int s_variable = 10;

int main()
{
    std::cout<< s_variable <<std::endl;
    std::cin.get();
}

>static.cpp
static int s_variable = 5; //static means this variable is only going to be linked internally inside this Translation unit


<OUTPUT: 10

# 3 
>main.cpp
#include <iostream>

int s_variable = 10; //global variable

int main()
{
    std::cout<< s_variable <<std::endl;
    std::cin.get();
}

>static.cpp
int s_variable = 5;

<OUTPUT : ERROR
error because this s Variable has already been defined in each different Translation unit so we can't have two global variables with the same name. 

# 4 things I could do to fix #3
* marking this variable as Extern which means that it's going to look for that s variable in an external Translation unit which is called external linkage or external linking.

>main.cpp
#include <iostream>

extern int s_variable;

int main()
{
    std::cout<< s_variable <<std::endl;
    std::cin.get(); 
}

>static.cpp
int s_variable = 5;

<OUTPUT: 5

# 5
>main.cpp
#include <iostream>

extern int s_variable;

int main()
{
    std::cout<< s_variable <<std::endl;
    std::cin.get(); 
}

>static.cpp
 static int s_variable = 5; //I mark this static It's kind of like declaring a variable private in a class no other translation unit is going to see this s_Variable the Linker will not see this in a global scope

<OUTPUT : ERROR


# 6 doing same for fuction
>main.cpp
#include <iostream>


void Function()
{

}

int main()
{
    std::cin.get(); 
}
>static.cpp
  static int s_variable = 5;

void Function()
{

}

<OUTPUT : ERROR

# 7 correcting #6
>main.cpp
#include <iostream>


void Function()
{

}

int main()
{
    std::cin.get(); 
}

>static.cpp
static int s_variable = 5;

static void Function()
{

}

* no ERROR
