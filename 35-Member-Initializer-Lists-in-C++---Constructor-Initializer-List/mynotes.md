* for reference go code #4
there is actually a functional difference different supplies to classes specifically if you write code such as this where we assign an M name to something here like unknown and you don't have it any member initializer list like 

>so what will actually happen is this M name object will be constructed twice 
once with the default constructor and then again with this unknown parameter 

>because 
what's happening here is actually 
this 
--->                                         m_Name = std::string("Unknown")

so you just credit two strings one of them you've just thrown away pretty much straight away right 

* it's a waste of performance right there

---------------------------------------------------------------------------------------------

you go that's the difference right you should be using member initializer lists everywhere right there's absolutely no reason not to use them if you don't like the code style get used to them because it's not just a matter of style it's actually there's actually a functional difference you'll be literally wasting performance if you're not using them of course not in all cases in the case of primitive types like integers you it wouldn't be initialized them until you initialize them yourself by assigning it but I

use it everywhere I don't discriminate between primitive classes in class types you should just be using initialized lists like this everywhere 