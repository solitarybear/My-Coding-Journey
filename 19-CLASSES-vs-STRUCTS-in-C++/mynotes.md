# cherno's style when to use struct and when to use classes

# struct
Let's talk a little bit about my style of programming and where I might use each type So I like to use struct whenever possible when I'm basically talking about plain old data or pod basically where I'm talking about some kind of structure which just represents variables a bunch of variables And that's really all it's there for.

A great example of this might be something like a mathematical Vector class if I were to come over here And I wanted to make some kind of structure which just held two floats together such as a Vec2 I might define it as a struct and just have my x and y floats 

why because fundamentally this Vec2 class or struct or whatever you want to call it, this Vec2 structure is just a representation of Two floats that's what it is 
at its core It's not supposed to really contain a massive amount of functionality like a player class might where it might be? Having it might like a player class 
might have a 3D model 
It might handle all the rendering code for that 3D model 
It might be handling like how the player moves around the map and 
taking in keyboard input and all of that 


There's just so much functionality there right whereas what this is. It's just two variables and we've grouped them literally just for the reason of Making our code easier to use that's all that we've done and of course that's not to say that I'm not going to be adding methods to this I absolutely Will 
I might add a method called add which takes in another Vec2 and then adds it to the current vector by doing something like this right,

but again what I'm doing here is I'm just Manipulating these variables I've just added a function that will manipulate those variables, but at the end of the day I'm still just talking about those two variables 

# class
now of course if you were really to break it down and think about it Really hard, then you could argue that At the end of the day 
even the player class is just manipulating those variables 

however There's a bit of a difference in terms of design Because we're talking about something that is massively massively more complicated 

the other scenario is inheritance. I will never use inheritance with structs if If I get to the point where I'm actually going to have an entire class hierarchy or some kind of inheritance Hierarchy I'm going to use a class for that because again Inheritance is something that's adding another level of complexity and I just want my structures to be structures of data

That's it and additionally to that if you try and mix those 

For example you have a class called A and then a struct called B Which inherits from A, some compilers will give you warning telling you that you're inheriting from a class But you're a struct and there are some other kind of minor differences, but again they're just warnings technically your code will still work it's just a bit of a semantical difference

