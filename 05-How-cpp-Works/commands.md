all the command we write in the terminal in vs code we indirectly using this pc's terminal as we can see the terminal history 

Commands 
1. Compile and linking together to make an executable file
             g++ main.cpp -o my_app

  g++:           "Hey compiler..."
  main.cpp:      "...read this file..."
  -o my_app:     "...and output an executable file named 'my_app'."

2. Run
            ./my_app
  ./:            "Look in the current directory..."
  my_app:        "...and run this program."          

Commands 
3. to make object file 
  g++ -c main.cpp
this command will only compile over cpp file and when we command g++ main.cpp it compiles and link both and skip saving object file 

4. To make executable below is pipeline how it made 
  full c++ build pipeline
  .cpp
       
 ↓
[Preprocessor]
 ↓
.i (not saved by default)
 ↓
[Compiler]
 ↓
.s (assembly, optional)
 ↓
[Assembler]
 ↓
.o (object file)
 ↓
[Linker]
 ↓
executable (ELF on Linux)
 
5. how to make a executable file when declaration and definition are both in deferent files 
 
  // Now if we try to make executable file there will be error as we hadn't define Log but when we build 
 
  //build is visual studios thing and in that when we click on build it tries to find definition of Log from other file as there may be mutltiple files to make a single executable file 
 
  //now to do that in vs code we will simply make object file (just compile) of where there is declaration and file where there is definition 

  //at the time of linking we will link them together to make a singal executable file 

  //in our case declaration is declaration.cpp and definition is log1.cpp
  
  //to link both files together we will use the command 
   g++ log1.o declaration.o -o log1_declaration
  
  //note for linking to files firstly we have to make those files as object file

  declaration file --- declaration.cpp
  definition file  --- log1.cpp



How to "Translate" Property PagesWhen The Cherno goes into Property Pages to change a setting, here is how you do the exact same thing on Linux using your terminal command (g++):
Cherno clicks in Property Pages...        You type in Terminal...        What it doesConfiguration:
 Debug                                    g++ -g                        ...Adds debug info so you 
                                                                        can track errors.
Optimization: Maximum Speed               g++ -O3                       ...Makes the code run faster 
                                                                        (O = Optimization).
Additional Include Directories            g++ -I/path/to/files          ...Tells compiler where to
                                                                        look for header files.
Linker > Input > Additional Dependencies  g++ -lGL                   ...Links a library (like OpenGL).