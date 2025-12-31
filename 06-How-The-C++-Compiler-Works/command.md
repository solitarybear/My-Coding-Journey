today in this lecture i findout various command (you can judge me beoz i'm new to Coding arena)

1. 'touch' command used for creating a file 
syntax -- touch xyz.cpp

2. 'less' command to terminal pager utility used to view the contents of text files one screen at a time
syntax -- less command.md

3. to get the .i file (preprocessed output)
g++ -E main.cpp > main.i

What this does
-E → stop after preprocessing

Expands:
#include
#define macros
removes comments
No compilation
No object file
Output is plain text C++ code

4. g++ -E   this command do same as 3 but instead saving into file it shows on terminal
syntax-- g++ -E math.cpp

5. g++ -E -P main.cpp -o main.i   
 this command Save clean .i file by removing all # texts 
 -E → preprocess only
-P → remove #line clutter
> → save to file


NOTE:- -E and -P are case sensitive 

 6. How to get assembly (.s / .asm) from a C++ file
 syntax-- g++ -S math.cpp
 What this does
-S → compile to assembly
Stops before assembling
No .o file
No linking

If you want Intel syntax (easier to read)
syntax-- g++ -S -masm=intel math.cpp

more easier to read
syntax-- g++ -S -O0 -g -masm=intel math.cpp -o math.s
where g is the debug symbol helps mapping

If you want to keep comments in assembly
syntax-- g++ -S -fverbose-asm math.cpp

Control optimization level (important)
syntax-- g++ -S -O0 math.cpp   # no optimization (best for learning)
syntax-- g++ -S -O2 math.cpp   # optimized

Full recommended learning command
syntax-- g++ -S -O0 -masm=intel math.cpp -o math.s

Assembly pipeline reminder
syntax-- .cpp → (.i) → .s → .o → executable


>    What “Debug” actually means
Debug build means:
easy to debug
readable assembly
predictable behavior
Command:
g++ -O0 -g main.cpp -o app

-O0 → no optimization
-g → include debug symbols
This is what IDEs call Debug mode.

>   What “Release” actually means
Release build means:
fast execution
optimized code
debugging is hard or impossible

Typical command:
g++ -O2 main.cpp -o app
OR
g++ -O3 main.cpp -o app

This is what IDEs call Release mode.


