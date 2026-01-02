>functions are basically blocks of code that we write that are designed to perform a specific task

 later when we get to classes those blocks are called Methods but when I say functions I'm explicitly talking about something that isn't part of a class 
 
 it's pretty common for us to split up functions to prevent code duplication we don't want to be writing the same code multiple times because of course if we did apart from copying and pasting a lot of code and just ending up with this huge mess it also means that if we decide to change some codee we have to change it in all of those places where we pasted the original code and that's just going to be a disaster to maintain so what

we can do instead is just write a nice little function that does what we want it to 
and then we can call it multiple times in our code if we need to 

you can think of functions as having an input and an output although they don't necessarily need to 

we can provide the function with certain parameters and the function can return a value for us so suppose that we wanted to multiply two numbers together and we wanted to write a function that did that so the


## Multiply function

the first thing I'm going to write here is something called a return value 
that is this is the type[int] that this function would return 

since we're multiplying two integers that of course will result in an integer so our return type is going to be int I'm going to give the function a name in this case multiply and it's going to take two parameters these are actually the numbers that we want to multiply together I'll just call them a and b I'll give the function a body and all this is going to do is return a * b so you

## f1.cpp
can see that we've got a function here that takes in two parameters both integers and simply returns the product of those two numbers 

## f2.cpp 
we don't necessarily have to provide parameters for example I could just not provide any parameters and return something like 5 * 8 this is still a function that returns an integer but it is just not taking any parameters

## f3.cpp
 we could also tell the function that we don't want it to return anything and we do that by writing void as its return type void of course means nothing so instead this could do something like log the result 


## f1.cpp

to the example here where we had int a and int B and we returned the product of those two integers so how do we call this function well calling a function is pretty simple let's go ahead and try and print the result of a multiplication I'm going to first of all make a variable which holds this result so I'll type in result equals multiply and we'll go with three and two so what

>>this is going to do is call this multiply function with these two parameters and 
>>then store the return value that is this result of a * b in this result integer 
>>we can then output that result result to the console 
>>let's hit F5 to run our program and after it builds you can see that we get six which of course is what 3 * 2 is so let's kick this up a 


## f4.cpp
 suppose that I want to do a bunch of multiplications and I want to log all of them to the console if I do something like that without a function then it would look pretty messy so for

example I need to repeat this code so let's go ahead and copy and paste it a few times I'll call this something like result 2 result 3 we'll do 8 * 5 90 * 45 and if I run my program and 
* oh hang on a minute 
why am I getting the same value everywhere oh look when I copied and pasted this code 
>> I forgot to change the variable now you may have thought that I did that by accident 

but I actually did it on purpose to prove something this actually happens all the time people copy and paste blocks of code and then forget to change one minor detail and in certain situations you might actually just run your program and not even notice that it's not working correctly Until It Breaks somewhere down the line and 

## f5.cpp
yet something like this can actually be fixed really easily if you just create a function for it so let's go ahead and fix this by actually printing out result 2 and three if I run this we will get our correct results which is great however you

can see that I'm actually calling this multiple times and it's just a little bit annoying like for example further down the road if I decide to replace this multiply function by simply doing something like 8 * 5 
look at this I have to replace it in every single place 3 * 2 90 * 45 that's 

## f6.cpp

I don't want to have to deal with that so this multiplication and then logging the result 
let's go ahead and make a function for that it'll be void because it's not really going to return anything to us it's just going to perform what we ask it 

to do we'll call this something like multiply and log and then let's take a look at which parameters we might want so what actually changes between these three blocks of code the values that we actually multiply that's it 

so those become the parameters for our function what actually changes between these blocks of code what needs to be specified for this function to perform its job let's go ahead and write in our parameters so 

>> we're going to be taking in two integers A and B 
* you can really call them anything you want but A and B seems sensible

 we'll copy and paste one of these blocks into this function this looks pretty good of course I'll replace three and two with our parameters so that we're using the parameters we specify into this function to perform the multiplication against which will cause a * b to get multiplied here and 
 
then we're going to be logging our result to the console so now instead of doing this so many times all I have to do is simply call multiply and log with my parameters so 3 and two for example and then we have 8 and five and then we have 90 and 45 and that's it 

look at that I can get rid of all of this code and this is what we end up with a nice clean and easy to read program if I launch my program you can see that we get the correct values here 



## by cherno
>> so this is a pretty simple example but I think it's effective in demonstrating that functions are really really important you should be aiming to split up your code into many many functions


however one thing that I want to stress is don't go [overboard] 
you don't need a function for absolutely every line of code that's not going to be good for anyone it's going to be hard to maintain your code's going to look messy and cluttered and it's actually going to make your program slower every time we call a [function_asterisk] 

>> the compiler generates a call instruction what this basically means is that in a running program in order for us to call a function we need to create the entire stack frame for the function meaning we have to push things like the parameters onto the stack we have to also push something called a return address onto the stack and then what we do is we actually jump to a different part of our binary in order to start executing the instructions from our function and that return value that we push we need to get back to where we originally were before we called the function 

so there's this whole like jumping around memory in order to execute function instructions and all of that takes time so it slows down our program 

now the reason I said asterisk earlier was because this is all assuming that the compiler decides to keep our function as an actual function and doesn't inline it 

we're going to talk in- depth about inlining in a future video so the reason I'm saying all this is because you don't want to just go ahead and create a function for absolutely every line of code don't be ridiculous about it it takes a little bit of experience to realize what you need a function for but basically if you see yourself doing a common task multiple times create a function for that the primary point of functions is to prevent code duplication 

we don't want to just be copying and pasting code everywhere now if we go back to our code for

>> just a second you might have noticed something a little bit odd about this main function it says that it return value is int however the return keyword is nowhere to be found and I'm obviously not returning anything so if I specify a return value do I actually need to return something 

let's go ahead and try and just do nothing in this multiply function I'll hitr F7 to compile my file look at this I'm getting an error telling me that multiply must return a value so do 

* functions with a return type actually need to return values 
>>the answer is yes they do 

>>the main function is actually a special function the main function and only the main function is exempt from this kind of must return a value if you don't specify a return value it will automatically assume that you're returning so it will be identical to if I had written this this is just a feature of modern C and C++ versions that lets you just keep your code a little bit cleaner 

and just for fun know that this must return a value thing is actually something that only applies in debug mode if we compile in release mode here you'll see that we actually don't get an error that's not to say that what we're doing here is correct because if we actually do capture that return value and decide to do something we will get undefined Behavior it's just that the compiler won't actually yell at us 

however in debug mode with certain debug compilation Flags enabled we will get an error which will just help us debug our code because at no point should you be writing a function that says it's going to return something but doesn't Okay 

so that's pretty much a basic introduction to functions functions are really useful I'm going to be writing a lot more of them in the future every program is built from a collection of functions so this is really important stuff if you don't think you fully understand how functions work don't worry because throughout this series we're going to be writing so many

functions that you're just going to get used to it and the best way to learn is of course to practice practice we also commonly break up functions into declarations and definitions so declarations we usually store in header files and then definitions we write in Translation units or CPP files