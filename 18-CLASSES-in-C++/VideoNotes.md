hey what's up guys My Name Is AO and welcome back to my C++ Series 

today we're going to be talking all about classes in C++ so we're finally getting into something called objectoriented programming which is a very popular way of programming 

object-oriented programming is really just a style that you can adopt as to how you write your code other languages such as C hash and Java are primarily objectoriented languages in fact you can't really write any other type of code I mean you can if you really really try but ultimately those languages are meant to be OB on to languages 

however C++ is something a little bit different because it doesn't really enforce a certain style upon you 

the language C for example doesn't actually support object AR programming because in order to have object AR programming you need to be able to have Concepts such as classes and objects and that's not something that's available in C however C++ does add all of that functionality if you wish to use it and it is almost always a good idea to use it to some extent 

so we're going to be talking about what classes are in this video to put it simply classes are just a way to group data and or functionality together 

for example 
think of a game in a game we might want to have some kind of representation of a player so what kind of things do we need to actually represent a player we definitely want some kind of data 

for example 
the position of the player in our game World certain attributes that the player might possess such as the speed at which the player moves we might also want to have some kind of 3D model that represents the player on the screen all of this data needs to be stored somewhere we could go ahead and create variables for all this in in fact 

let's go

ahead and take a look at what that would look like let's say that we want to make a player here in our code we might want to have a position so I'll just say X and Y and then potentially a speed let's just set the speed equal to two so these are all integers for now you can probably start to see that this is getting a little bit messy and in fact because these names are so generic

you might want to do something like player X player Y for the X and Y coordinate of the player maybe player speed and 

>this really does start to get a little bit messy especially if we decide 

* actually we want two plays in our game well then suddenly you're going to have to duplicate this and start doing something like player x0 player X1 

instead of this you could of course use an array but the point is still the same it's just kind of a bunch of variables that aren't grouped together they're just unorganized they're just sitting in our code and it's just not a good idea 

another great example 
of why this is annoying is because if I want to write a function that moves the player or something like that I suddenly need to be specifying all three parameters as integers so for 

for example the x coordinate the y coordinate the speed all of this just becomes so much code and so difficult to maintain and follow that it's just it's really really messy 

* so what we can do instead is simplify this by using a class 

* we can create a class for the player we can call it player which contains all of that data that we want all those variables kind of in one type 

so instead of this let's create a class called Player we do so by just using the word class and then giving it a name 

* this has to be a unique name because cuz classes are types we're basically creating a new variable type and then we open and close curly brackets as if this was a function 

however note that we do actually need a semicolon at the end of the closing brace

inside here we can specify all of those variables that we did below 

for example 
X and Y for the position and then a speed variable as well all right great so there we go we've created a brand new class called player 

which is essentially its own type so if we were to start using this player class we can create it as 

if it was any other variable we write the typee so player and then we give it any name I'm going to call this player and that's it we've created a new variable called player which has the type Player and of course the definition of that type is over here variables that are made from class types are called objects and a new object variable is called an instance 

so what

* we've done here is we've instantiated a player object

because we've created a new instance of that player type now if we want to set those variables we can simply write player Dot and then the variable name such as X and then assign it equal to something like five if we try and compile this code right now 

we're actually going to get an <error 

that tells us that player cannot access private member declared in class player this is because of something called visibility 
when you create a new class you have the option to specify how visible the stuff in that class actually is by default a class makes everything private which means that only functions inside that class can actually access those variables 

however we want to be able to access these variables from the main function so what we actually need to do is come up here and make it public public means that we're allowed to access access these variables outside of this class anywhere in our code really we'll talk a lot more about visibility in a future video I don't really want to get into it right now so you can see if we compile our code here then our code compile successfully okay pretty sweet 

>so we've achieved our first goal we've managed to drastically clean up the code and have all of our variables in one place 

because really this collection of variables represents a player so we've managed to group it nicely now that we've got all this data suppose that we actually want our player to do something for example <move somewhere so we need to write a function which changes the player's X and Y variables 

>how can we do that well 

we could write it as just a standalone function 

so I'll write void I'll call it move and then I would need to take in the player that I would like to move now we'll have to pass this by reference because we'll actually be 

* modifying the player object and then I'll also take in XA and ya which will be the amount that we move the player by in both X and Y 

then all I need to do is just say playerx plus = XA and player. Y plus = y a we can also use that speed variable that we have there by multiplying our amount by the speed all right pretty cool and 

if we wanted to call that we would just write move player and then by how much we want to move the player so maybe 1 - one and there we go we've written a function that can move the player however 

* we can do a little bit better than this 
earlier I said that classes can actually contain functionality so what that basically means is that 

we can move that move function of ours into the class and functions inside classes are called Methods so I can literally go over here into my code and just move this a little bit up so that it's inside the player class and there we go now obviously we're in inside the player class now 

so we actually have access to these variables we don't need to pass a player object in because we're already inside a player object so if I get rid of this and then all of these the X and Y and speed that we're referring to will be the current objects variables if I come down over here I can change my code now to just say player. move and there we go 

we've simplified our code quite a bit every player object is going to have its own move function and 

when we call move for that specific player object that is the player object that will move again 

>this isn't really any different to having the move function outside of the player class all it does is it kind of cleans up our code and makes everything look a little bit nicer and that's a huge bonus when you're dealing with a lot of code because the more code you have the more complicated it can get and the harder it can actually become to maintain that code 

so having things like this to keep your code cleaner is actually a very very welcome thing so that's it that is essentially the basics of what classes are 

classes allow us to group variables together into a Time and also add functionality to those variables because if you take a look at this code one more time 
what we've really done is we've just defined three variables that kind of exist in one type and also a function which manipulates those variables that's really all we've done of course that function can do literally anything but the gist of it is we've got data and functions to manipulate that data and 

that's really all the class is 

now there are so many uses for classes and we'll kind of start getting into them in the future this is also literally just a basics of what a class is there is so many more things we can do with classes which is why the next few videos are going to be taking a look at those things in more detail also I want you to keep in mind that whilst 

classes are extremely useful and can keep your code a lot cleaner 

they can't do anything that you can't do without classes 

classes don't give you any kind of new functionality that you could not have done otherwise anything you can do with classes you can actually do without classes 

which is why languages such as C exist and are perfectly usable languages they don't have classes and yet we can still write code classes are just there to make our lives easier as programmers they're essentially just syntactic sugar that we can use to organize our code and make it easier to maintain that's all that they are anyway I hope you guys enjoyed this video if you did please hit that like button you can also follow me on Twitter and Instagram and of course next time we'll be taking a look at this stuff in more detail and seeing just what we can do with it [Music] goodbye