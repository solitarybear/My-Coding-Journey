//this is the first log file (after shifting log material) made by cherno explaining error over terms not recognise by compiler
#include <iostream>

void Log(const char* message)
{
    std::cout << message << std::endl;
}
//this above succesfully compiled but when we try to make exe file it shows error as below
///usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':(.text+0x1b): undefined reference to `main'collect2: error: ld returned 1 exit status


//that is becoz → This only compiles → It creates an object file → log.o → No linking happens → So no main() is required yet