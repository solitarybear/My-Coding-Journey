#include <iostream>

//a declaration looks very simalar to definition the file named log.cpp is something what definition 

//such that in that file early we declared something called log and then we also given body which actually contains what code will run when we call this function 
void Log(const char* message); //here we doesn't need to name of the parameter (message) as it doesn't matter if we remove message that doesn't affect 


int main()
{
    Log("Bolo zuban kesari!");
    std::cin.get();

}
// Now if we try to make executable file there will be error as we hadn't define Log but when we build 
//build is visual studios thing and in that when we click on build it tries to find definition of Log from other file as there may be mutltiple files to make a single executable file 
//now to do that in vs code we will simply make object file (just compile) of where there is declaration and file where there is definition 
//at the time of linking we will link them together to make a singal executable file 
//in our case declaration is declaration.cpp and definition is log1.cpp
//to link both files together we will use the command g++ log1.o declaration.o -o log1_declaration
//note for linking to files firstly we have to make those files as object file 