one other thing to note with the return statement is that 
>you don't have to use return inside a loop the same way that you have to with continue and break 
* return can be written anywhere so I could do something like if five is greater than 8 return Z and of course I have to provide a value in this case because this function returns an integer 

so return not necessarily inside a loop can be absolutely anywhere in your code 

you also don't even have to have an if statement 
you could have something like this but of course in this case there is no circumstance under which this line would get triggered so this is actually known as dead code and 

some compilers especially in other languages will actually restrict you from writing code like this because I mean at this point you might as well just delete this line it's never going to get called 