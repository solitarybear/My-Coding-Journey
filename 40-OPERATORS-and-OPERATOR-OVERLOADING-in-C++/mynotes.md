the time overloading in this sense just means kind of giving a new meaning to or adding parameters to or creating essentially in the case of operator overloading you're allowed to define or change the behavior of an operator in your program this is a very very useful feature that isn't supported in languages such as Java it is partially supported in languages such as C sharp usually the good parts of it are supported 

but if I suppose kind of gives us full control and that's kind of it's kind of a good thing but it can also be a bad thing and that's just the case with C++ it gives you so much control but it can lead to so many bad programs 

>> operators are just functions they're just functions instead of giving your function and name such as add you can give it an operator such as plus 

* however in other cases if you're using the ampersand operator to push a variable into a data set 
    what are you doing--

* at the end of the day your use of operator overloading should be rather minimal and only in cases where it makes perfect sense if people need to go to the definition of your operator or the definition of your class or struct or whatever to see what it actually does then then you've probably failed 
for example when defining a maths class and you need to add two mathematical objects together than overloading the plus operator makes perfect sense because you can literally write code like a plus B and it will work 




# by TheCherno
I said I'm not going to go through every single operator because that would take all day and it's probably not that useful I will make future videos on operators as we use them or as I see fit


> -- 
our just operates work in general room but they're

just functions and remember just because you can overload an operator and make your code look weird don't because it's going to make it harder for people to read is probably going to annoy you yourself and it's just it's just bad just bad code style don't do it this let's shift operator that we overloaded just kind of like the two string function that you commonly override in languages such as Java or C sharp and so that's one of the great things about C++ you can kind of have operators instead of functions another great

example which c-sharp does support but Java doesn't is the equals equals operator in Java you have to write an equals override for every class if you want to be able to compare it and then later on you have to write equals everywhere so compare result one result - 