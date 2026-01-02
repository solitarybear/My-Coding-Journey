>> we're here somewhere in Australia and we're going to be talking about C++ I hope you guys don't start to think that header files are so boring

>header files what are they why do we need them why do they even exist in C++ a lot of other languages that you might have been used to like Java or C they don't actually have header files or any kind of concept of of of two different file types where we have our compilation file that we actually compile like I said Plus+ file a translation unit and then we also have a header file which is just this weird kind of file that we always include in places and why is it even there header files are actually much more useful and they're used for much more than just to kind of declare certain declarations that you want to use in multiple CPP files 

## header files 
header files are traditionally used to declare certain types types or functions so that they can be used throughout your program 


for example if 
we create a function in one file and we want to use it in another file C++ isn't going to know that that function even exists when we try and compile that other file so we need a common place to kind of store 

* just declarations not definitions 
because remember we can only Define a function once we need a common place is to store declarations for functions just declarations no actual definitions no body for the functions 

but just a place that says hey this function exists let's take a simple example here so 

* suppose that I have a function here called {log that is supposed to log something} to the console 
# main.cpp and log.cpp
it's going to take in a (constchar message) and it's going to Simply see out that message if I then go ahead and 

create an additional file we're going to call this <log.cpp and then maybe that additional file has something that initializes our log and decides to log something to the console we're going to get an error because this log function doesn't actually exist in this file 

this file doesn't know about the log function of course back in main here it is the log function exists fine and we can actually replace our hello world logging to use that log function and if I try and compile my program by hitting contrl F7 you'll see that it works fine and we don't get any errors however back

>>in log if I try and compile this we get an error because of course as far as this file is concerned log doesn't exist so what does <log.cpp actually need in order to not error us how do we tell it that 

that log function does actually exist but it's just defined elsewhere that is where a function declaration comes in 

if we go back to our code here I need to Simply declare that log does exist if we go back to main and we take a look at this actual signature 
you'll see that log is a function that returns void and takes in one parameter which is a const char pointer 

so this is the function signature we can literally just copy this go back to log.cpp paste this in and just close it with a semicolon the fact that this function doesn't actually have a body means that it is the <Declaration of the function we haven't defined 

what the function actually is what the function actually does we've just said hey there's a function called log that returns void and takes in a const char pointer we've that that function exists

you can see that our intellisense error has gone away and if I hit contrl F7 we do compile and if I right click on hello world and click build to actually build my program you can see that it links fine as well because it's F it's found that log function all right fantastic so great

we found a way to actually tell our log.cpp  that log function exists somewhere but what if we make another file what if I make some other file that needs to use this log function does that mean that I also have to copy and paste this void log declaration everywhere 
>> I go the answer is yes you actually do need to do that 

however there is a way to make that easier 
header files right what are header files what are head files traditionally I should say because really this is C++  you can do anything with anything 

but header files are usually files that get included into CPP files so basically what we do is we copy and paste the content of header files into CPP files and we do that via [the hash include] pre-processor directive 

so hash include has the ability to copy and paste files into other files and that is exactly what it seems that we need to do here we need to copy and paste this log declaration into every file that needs to use that log function 

# log.h
so let's have a go at making a header file I'm going to write click on header files now note these folders here are called filters they're not actual real folders I can create a header file under source files  for now just know that these are kind of fake folders it doesn't matter which one you right click on to create your header file I'm going to create it under header files


because that makes sense but it doesn't really matter I'm going to make a header file called log. you'll notice that it straight away inserted some code for me automatically that says 
>#pragma 
once we'll talk about that in just a second so here I'm going to put in my declaration I'm going to cut my declaration from the l.cpp file and put it into here into my header file so now the idea is this this header file log.h 

I can include everywhere where I want to be able to use log and of course it's going to do for me what I didn't want to do manually and that is copy and paste this everywhere throughout every file that requires it I don't want to have to do that copying and pasting myself so 

I've basically found a way to kind of make it look a bit tidy and automate it to some extent so back in  l.cpp you can see we get an error now because we're not actually declaring that function however if I type in hash include log. check that out we don't get an error and our file compiles fantastic what we can also do is actually included into m.cpp now m.cpp contains the actual definition for the function 

# l.cpp and m.cpp

so it doesn't really require it we can call log anyway but just so you know it's not going to hurt for us to actually include log.h into here and compile that's not going to be a problem all right so back in    l.cpp you can see we've defined this fantastic function called nit log 

however no one actually knows about it except for log to CPP if I want to be able to call it from Main I'm going to need that declaration if I call init log over here it's going to give me an error because that's not declared anywhere 

so let's go ahead and add that function signature in it log into our log header file just like that fantastic make sure that it matches the function signature that you've actually declared in your in your CB file 
so now everything seems well in the world I'm also going to go ahead and cut and paste this log definition into my log file because that makes a lot more sense now I get an error here telling me see out is not found that's okay I can just include IO awesome so backin main 

# lm.exe

if I run my program we can see that we managed to
initialize our log and then log hello world to the console fantastic all right brilliant so 


# pragma once
let's go back to that header file and take a look at what that pragma one statement actually was so here we have a statement that Visual Studio has seemingly inserted for us called hash pragma once what is this so 

>firstly anything that begins with a hash is known as a pre-processor command or a pre-processor directive 
it means that this is going to be evaluated by the C++ pre-processor before this file actually gets compiled pragma is essentially an instruction that is sent to the compiler or to the pre-processor and what pragma once essentially means is that only include this file once 

>>so pragma once is something called a header guard 
what it does is it prevents us from including a single header file multiple times into a single translation unit now I chose my words there very carefully 

* because you have to understand that it does not prevent us from including our header file into multiple places in our program just into a single translation unit so a single CPP file the reason is that if we accidentally include a file multiple times into a single translation unit we can get duplicate errors

because we'll be copying and pasting that entire header file multiple times one of the best ways to demonstrate this is if we were to create a struct 

# h.h
for example if I create a struct here called player I can leave it empty it doesn't really matter if I were to include this file twice into a single translation unit with no heer Gods 
it would actually include that file twice which means that I would have two structures with exactly the same name player 

# l2.h
we can take a look at this example by commenting out our pragma once and then back in log I will include l2.h twice if I try and compile my file you can see that we get a player struct redefinition error because we're redefining that struct player we can only Define one struct called player structs need unique names so again

you say chero why would I do this I'm not a stupid programmer I'm not as dumb as you think why would I include a file twice 

well young one this comes back to 
>how include Works 
remember how include works is it copies and pastes files into to other files 
meaning you can create a bit of a chain of includes so you could have a header file called player 
which includes log 
then players included in some other file 
and then maybe that third file contains every include 
so if I create another header file here called common 

# common.h
common is just going to contain some common includes for example it will include log if I go to l2.h and make sure that pragma once is commented out and into l2.cpp I include l2.H and common.H 

if I compile my file guess what I still get that error because that struct player is being redefined if we were to resolve what the pre-processor actually did you could see that it actually has included log twice 


however back in log. 
if we get rid of that comment and try and compile our file we don't get an error because it recognizes that log is already been included and it does not include it twice now there is one other way that we could add a header guard 

>>and I actually kind of like this four teaching purposes 
because it makes a little bit more sense than some kind of pragma once although pragma once does look a lot cleaner 

* the traditional way to add header guards is via  <ifndef 

# l3.h
so what we can do is we can actually type in an 
if and Def and then we can get it to check some kind of symbol 
for example log H we're going to Define log H and then at the very end of our file we're going to type in end if 

so what this is going to do is first of all check to see if a symbol called log H is actually defined if it's not defined it's going to go ahead and include the following code in compilation if this was defined then none of this will be included it'll be all disabled 

so once we do pass this initial check we're going to Define log H which basically means that next time we go through this code it will be defined 


# l3.cpp
so it will not be repeated a really easy way to demonstrate this is just to copy and paste this entire file into our l3.cpp file and then if we take a look at this I'll also comment out l3.H and common. H so 


you can see over here that the first time this is all fine it includes the file and everything's okay and 

then the second time it's all gray out because log H has already been defined so this kind of head of guard is something that was used a lot in the past however 

> now we have this new pre-processor statement called pragma once 
and so we mostly use that it doesn't matter which one you use to some extent although pragma once is a lot cleaner 

so it's something that I personally use and it's something that most people do use in the industry pretty much every compiler now supports pragma one so there isn't it's not like a visual studio only thing GCC clang msvc they all support once 

so don't be afraid to use it that being said if you do find Legacy code or just code the people have written using different styles you may encounter this if and Def header guard so just be wary of what it is but again I would never write if and F 

I would always use pragma ones the last thing I want to show you is with header guards we have this kind of discrepancy between 

* include statements some include statements use quotes some include statements use angular brackets what is the deal deal is actually pretty simple they mean two different things when we compile our program we have the ability to tell the compiler of certain include paths these are basically paths to folders in our computer that contain include files 

# <   >
>>if the include file that we want to include is inside one of these folders we can use angular brackets to tell the compiler to search our include path folders 

# "  "
>whereas quotes on the other hand are usually used to include files that are relative to the current file so 

# l5.h
for example if I had a file called l3.h that was up One Directory from this current log. CPP file 

> ../
I could use do flash to go back and that would actually go back to a directory because this is relative to this current file 

>> whereas with angular brackets they are never relative to this current file they just have to be in one of the include directories we'll talk more about setting up include directories and all that in the future I don't want to complicate things too much but that's

basically the gist of how this works 
* now quotes can also be used to specify files that are relative to include directories that are pass to our compiler 
* so you can actually use quotes anywhere 

# l5.h
I can replace this IO stream to be in quotes and it would totally work so angular brackets only for compiler include paths quotes for everything 

however I usually like to use them just for relative Parts 
since you might as well use the angular brackets for something all right 

final thing for today one other thing that you might notice is this IO stream doesn't actually look like a file because it doesn't contain any extension it's just called iostream 

>what's up with that 
well it actually is a file it's just that it doesn't have an extension this is something that whoever wrote the C++ standard Library decided to do to basically separate out C standard Library header files and C++ standard Library header files 

header files that are in the C standard Library will often have a h extension on the end 
however C++ files do not so this is just one other way you can differentiate between what is in the C standard library and the C++ standard Library whether or not it has that .h extension 

iostream is a file just like anything else in fact in visual studio if we right click on it and hit open documents you can see that it takes us to this IO stream header file and if we right click on it on this tab here and hit open containing folder you'll see where it's actually located on our computer inside this directory and 

here it is that IO stream header file all right so that's it header files pretty easy we're going to be using this extensively in this series 



goodbye [Music]