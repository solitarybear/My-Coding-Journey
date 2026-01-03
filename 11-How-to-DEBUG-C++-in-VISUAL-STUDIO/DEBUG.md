## Debugging
though debugging is just such an important part of programming and not just programming but of learning because if you know how to debug your code you're actually going to understand how the program works and how the computer actually runs your code 

so I thought I'd covered debugging pretty early on in this series because I'm actually going to use a lot of what we cover today to explain how the rest of the language and how computer programs work in general 

>> in this video specifically like all of my C++ videos I'm going to be using visual studio however these Concepts apply to pretty much any IDE out there most idees will support exactly what I'm going to show here today just might be in a different place but 

>> break points see that joke earlier was funny cuz break points is a big part of debugging and looking at memory so break points and reading memory those are kind of the two big parts of debugging and of course you will be using them together so 

in other words you'll set break points in order to read memory 

so what's the point of debugging what do I mean when I say let's debug our code the word debug means to debug right so to remove bugs from our code 

in order to remove a bug from our code we have to diagnose what's wrong with our program and that part can actually be pretty tricky even if you're well experienced in the language at the end of the day you have to remember that the computer is always right and by always I mean like 99% of the time it's very unlikely that you did something correctly and then the computer just didn't work as expected it's usually it's 

usually you who made the mistake and coming to realize that is something that is very important for programmers you will soon learn that the computer is pretty much always right so really

>>this is all about figuring out your mistake what did I do wrong what did I do to deserve this 

so break points reading memory let's take a look so here I have a pretty simple Visual Studio project 

# main.cpp, log.cpp, log.h
I've just got my main file here which calls log this is the log. CPP and log. that we made in the previous video in the video about C++ header files what we're going to do first of all is we're going to set a breakpoint and then we're going to step through the execution of our program 

# BreakPoints 
so what are break points so a breako is a point in our program at which the debugger will break and the word break here just means pause so what will happen is we can basically set a break point on any line of code in our program and when when the execution hits that line it will pause 

it will suspend that execution thread or in our case the entire program and let us take a look at the state of this program and 

>>by state I'm really referring to memory we can pause our program and just take a look at what is going on in its memory 

remember the memory of a running program is pretty much all it's got It's what every variable is set to it's what function will be called Next everything when you when you break it down memory is all all that there is really so being able to view Memory is incredibly useful in diagnosing what the issue is with your program because by viewing the memory you can see what every variable is set to and be like hey this variable shouldn't be set to this value something's obviously wrong 

you can also step through the execution of your program line by line so I can put a breakpoint on line five and then just just hit a button and the program will advance just one line of code further into line six you can also step into functions to see where they'll take you there's just there's so much you can do with break points it's amazing and it's incredibly useful and 

* if you're programming without this then I don't even know what you're doing 

# as im using Linux and vs code there's pretty much different from the Cherno's Visual Studios so  i have edited launch.json and task.json such that i can get console window like cherno got and to debug 

# launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug C++ (External Console)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Build with g++"
        }
    ]
}

# tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Build with g++",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.cpp", 
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Compiler task that builds all .cpp files in the folder."
        }
    ]
}

so back to visual studio in order to set a breakpoint in Visual Studio you can either 
* just hit F9 and it will set a breakpoint on that current lineup code or 

* you can can click on this sidebar anywhere on the sidebar here just click once and you'll set a breakpoint 

obviously if you do something like set a breakpoint on line three that's not really going to work because there's nothing on line 3 <main.cpp that's ever going to get executed so make sure you set a breako on code that actually will be executed on lines that will actually be hit so line six of course will be hit because that's the first line of code in our program and then all you have to do is run your code through the debugger 

* one tip is to make sure that you're in debug mode because if you're in release mode the compiler will actually change the the way that your code looks and your break points might not ever get hit 
because your program has been rearranged we'll talk more in depth about what release mode actually does and all that stuff later 

* but the gist is if you're debugging just make sure you're in debug mode 
if we then hit the local Windows debugger which ensures that we're actually running with the debugger attached our program will run and you can see that 

the focus from our program is actually stolen back to visual studio and we change into this kind of different alternate layout 

>along with a big yellow arrow on on that breakpoint indicating that that is currently where the instruction pointer is at in our program 
the main areas to look at here are basically this continue button which will continue executing our program like normal and 

* then we have a bunch of buttons over here that let us step into step over or step out 
now these three buttons are going to control exactly what happens next in our program so 


# stepinto or F11
>step into is going to step into the current function that is on this line of code if there is a function so in this case if I hit step into onto log 
we would actually step into the log function 

# step over or F10
>so that we could see what it does step over is going to step over to the next line of code in this current function 

# step out or shift f11
>and step out is actually going to step out of this current function and take us back to whatever called this function which in this case since this is the main function will be the C standard Library 

you can also use f11 to step into F10 to step over or shift f11 to step out so 


let's step into this log function and see what happens I'm going to hit f11 okay check this out so we step into this function where at the very beginning of the stack frame we haven't actually begun executing any code here we're just setting up the function stack frame 

>we can hover our Mouse over this message variable and check this out it tells us 
that it's set to hello world so that's the second part of debugging right we're reading memory now 

how cool is this if I hit F10 it's going to bring us up to this line of code now the fact that 

* the yellow arrow is on this line of code means that it actually hasn't executed this line of code yet it's just it's on there it's about to as soon as we hit a button like F10 or shift f11 to get out of the function or F5 which will continue our program as soon as we hit one of those it's going to execute that line of code and possibly more 

but the yellow arrow means that it is on that line of code it hasn't actually executed that line of code yet so if I bring up my program right now you can see that that hello world message has not been printed but check this out if I hit F10 and then check back look at that we've printed hello world because we've called that s CDC out function and it actually has printed that text to the console we've executed that function so by setting break points and by stepping through our program we can literally run our entire program line by line which of course is really cool and really useful when you're trying to figure out what you've done wrong anyway 

back here if we keep hitting F10 you'll see that we'll eventually get back to our main function F10 again will bring us to the next line of code in our main function and this will kind of keep going if I hit F5 it's going to continue running our program as usual and I can just hit enter to close my program as if it was just running normally all right 

so pretty cool stuff and even though this might look really simple this is actually really all there is to it I mean I've shown you guys pretty much everything I'll show you some more examples so that you really get it but that's kind of the gist of it 

# now for code #2 in code.md

so let's go ahead and make some more variables to make things interesting I'm going to make an integer called a set it equal to 8 I'm going to do A++ which will increment a by one so in

other words it will set a to be 9 I'm going to create a C string here by just typing in Conch string equals hello I'm going to write a very basic for Loop here that's going to iterate through this string and print each character out on a separate line and then I'll leave in my log Holo world for good measure so if I run my program with no break points at all just to see what even happens you'll see that we get basically something like this where we have hello and then hello world all right now let's

step through this line by line so I'm going to set a breakpoint at the very top here on int a and just hit F5 all right all right cool let's take a look what a is what why is it 858 million well remember that yellow arrow doesn't mean that we've actually run this code we're actually just about to run it but we haven't actually executed line six the line that actually creates and sets that a variable so what

the debugger is currently showing us is what the memory where a would be is showing right now and since we haven't actually set that variable to anything yet it's just **uninitialized memory** which means that this value is just showing us whatever that memory actually contains this would be a fantastic time to bring up these three important windows that we have here 

>autos 
>locals and 
>watch utos and 
>locals will basically just try and show you local variables or variables that it thinks might be important to you watch on the other hand 

# under Watch
* lets us actually monitor variables so what

I can do is I can type in a which is the name of the variable and hit enter and you can see that it's showing me the value of a 
if I also want to viiew what string is I can also put that in and it's going to show show me what string is now 
of course we haven't initialized this memory yet so it's currently it's completely useless it's just garbage but as we step through our program these values will update to show what's actually in the memory 

* speaking of memory there's actually a view that we can use to view the entire memory of our program now of course it's called the **memory view** 

so if we go debug Windows memory and memory one we're going to be graded by this weird looking panel here that's going to show all of the memory of our program so on the very left we see the memory addresses in the middle we see the actual data the actual values represented in heximal format and on the right we see the asky interpretation of those numbers if you want to locate where this a variable actually is stored in the memory of your program you need to know its memory address and to do that we can simply type in 

* & and a ------&a
* in our case we use debug console near terminal and the comman is 
# -exec x/16xb &a


so the Ampersand in front of a variable name will actually get that variable's memory address if we hit enter we're going to be taken to the memory address of that a variable which in this case is a whole bunch of C's 

# cc cc cc cc
so that number that CC number is actually a heximal value if you want to see what that is in decimal you can bring up a calculator if we switch to the programmer view we can type in the heximal value if I just click on hexadecimal here type in CC and you can see what that value is in decimal it's 204 so 204

CC why is it said to that isn't that memory just supposed to be random a whole bunch of CC's seems kind of specific now that's the cool thing about debug mode and 

>also why debug mode slows down our program it's because the compiler will actually make our program do certain things certain extra things that's going to make our lives easier when it comes to debugging so for example the fact that this memory is a whole bunch of CC's means that it is uninitialized stack memory so what's actually happened is the compiler knows that we're making we're trying to make a variable but we haven't initialized it yet so what is going to do is actually fill that memory with CC so that if we're debugging our code and something goes wrong we can look at the memory we we can see that it's set to CC and we can be like oh of course I never initialize that variable that's why this is going all wrong 

now by doing extra things like that like setting our memory to CC before we initialize it obviously our program is doing extra things that are going to slow it down so we don't want to be doing that in release mode when we actually release our program when we ship our game we don't want to be doing all that but when it comes to debugging is so useful so if I come over here and I hit F10 a lot of things are going to happen one other thing you you can do actually in this watch window is right click and select hexadecimal display and so now

you can see that the value of a actually is a whole bunch of C's which of course means that a is currently uninitialized stack memory let's go back to our non-hex aimal display and 

# F10
let's hit F10 and a number of cool things are going to happen so namely in this watch window our value has changed to eight it's also red which indicates that it's changed since the last break point our instruction Point has moved down which is showing that it's now about

about about to execute this line of code hasn't done it yet no no no not yet but it's about to and then if we look in our memory view you can also see that these four bytes of memory have been set to eight by the way I should probably mention that 

* every two digits here is equal to one by that's also why we're viewing this in hexadecimal because if we do that every two heximal digits are always going to align to be one bite of memory so we

can tell just by looking at this that these eight heximal digits are four bytes of memory and you can see that it's been set to8 so that's what we're doing that's all we're doing right now we've paused our program and we're taking a look at its state we're reading its memory 

# again F10
if I hit F10 again we're going to advance this is now set to 9 it's set to 9 here as well pretty cool stuff you can see that string is still uninitialized stch memory but check

this out I'm about to initialize it aren't I so if 

# f10
I hit F10 it's initialized because this is an actual pointer it's also telling us the memory address of that string so if I was to copy this memory address here from the watch window and paste it into my memory View and hit enter look at this I'm taking to these bytes which in this ask interpretation you can see that 
* it says hello and what's really interesting is that if you actually keep reading you can see that our program literally contains memory 

close to this hello variable that says stack around the variable was corrupted the variable is being used without being initialized obviously our program containing string like stack around the variable was corrupted in its memory is not something that will exist in release mode but it's

just another great example of what will actually happen in debug mode to help you debug your program Okay cool so things are getting really interesting here because we've run into this for Loop what's going to happen if 

I keep advancing through this now we haven't covered for Loops or any kind of control flow statements in this series yet the next few videos are probably going to deal with it I really wanted to cover the debugger first so

>that we can actually step through these control flow statements in the future and see how they work and you guys already know how to use this debug view but basically f is going to do stuff multiple times so if we step through this program you can see that 

<i> set to zero it's going to grab index Zero from this string which is going to be the very first character in the string which is a capital H if we hit F10 we can hover our Mouse over C and see that it's set to H 

we can also come over here into watch and just type in C and you can see we're now taking

a look at what C is when 

I hit F10 it's going to log that letter to the console and then when it gets back to this curly bracket it's going to run this comparison it's going to compare is I less than five and then if so it's going to increment I and 

then jump back into here so if I hit F10 you can see we jump up here to do the comparison if I hit F10 again we've done the i++ I is now one

we're going to do the same thing all over again except this time I is one so it's going to grab the second character which is the letter e and continue on in this case see is equal to e you can see that it's changed here in our watch if we come up here do Ampersand C and hit enter you can see we have 65 which is the letter e according to our ask view fantastic I can keep running through this and everything's going to be great now suppose

* that I wanted to exit this for Loop and maybe jump to this log function I don't really care about stepping through this

 I get how it works how do I get out of this for Loop if I try and step out or hit shift f11 it's actually going to exit the whole function I don't want to do that that I just want to kind of keep running the full loop and then stop here how do I do that well it's pretty simple 

* all you have to do is put a breako on where you want to stop next and if I hit F5 or press the continue button up here it's actually going to run my program until it hits the next breakpoint

which in this case is this log function so by this point you can see that the memory that used to make up this C variable is set to O it's actually still active that memory is still there even though we've gone out of scope and we'll talk about that in the future but the memory is set to the very last character of the word hello and if we bring back our program you can see it's printed up that entire hello word and then we're about to execute this hello world log if I hit F10 we're going to jump to the next line

of code here it's going to print hello world now we've actually paused execution of this program because we had a break point here and I just hit F10 so if I press enter here nothing's actually going to happen I need to hit F5 and then our program will close because it is going to still detect that enter press so that's it a fantastically simple overview of basic debugging there's going to be a lot more to this but what

I just showed in this video is going to be the basis of how we actually debug our code remember a program is really just made up of memory even the instruction pointer which is where in our program we actually are executing code and the actual code that we're executing all of that is stored in memory so being able to view our memory is really all we have and really all we need and by setting break points it lets us pause our program at a give time at a given line of code and actually inspect it and take a look to see what all of our variables are set to which of course is going to be incredibly useful when you're running code hope you guys enjoyed this video if you did please hit that like button let's see

if we can beat our like record I don't know I think it's about 800 so let's just let's just let's just smash that you can follow me on Twitter and Instagram I've been posting some pretty cool photos on Instagram lately so you're just you you're just not going to want to miss that at all and if you really like this series you can support me on patreon.com Theo now the cool thing about this is by doing so you'll

get access to early drafts of videos and the cool thing about those early drafts is not everything in the draft makes it to the final video to this so you get to see stuff that might be cut from the final video exclusive and as well as that of course you are supporting this series and you're enabling me to make more of these videos more often which is pretty awesome awesome hope you guys have a great day and I'll see you in the next video


# some images are uploaded through the folder <assests showing the what we performed looks like