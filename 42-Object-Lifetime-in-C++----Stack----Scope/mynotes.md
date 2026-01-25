# two major steps we learn in this lecture
* the first part is kind of you have to understand how things live on the stack in order for you to actually be able to write code that doesn't crash and code that works but also this actor set 

the next step once you know how this works is that I now know

* how to leverage this and make it kind of do what I wanted to do and come up with clever ways to do things

# for better understanding rewatching the lecture video is must 

# smart pointer some example ~ TheCherno
they're a very important part of the language so this kind of automatic creation an automatic destruction that we can kind of get from the fact that a stack based variable goes out of scope and gets destroyed is actually really useful 

and there are plenty there are plenty of more examples just to name another one off the top of my head a timer 

let's just say you wanted time how long you are inside a scope for benchmarking or something you could write a time a class which starts the timer upon construction of the object and that stops the time I maybe prints the result or whatever when the object when the timer object gets destroyed so suddenly you've got an automatic timer you just write one line of code at the beginning of your function and that entire scope is going to now be timed and you turn and you never have to call time it'll stop or whatever manually 

because as soon as it goes out of scope and calls that for you automatically it's really amazing and there's so many uses for it another one is mutex locking 

if you want to lock a function so the multiple threads can't access it at the same time and caused an explosion you can have an automatic scoped lock which at the beginning of the function locks it and at the end of the function unlock

