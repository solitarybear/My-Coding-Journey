> the main purpose of new is to allocate memory on the heap specifically you write new and then you write your data say whether that be a class or a primitive type or an array based on what you've written it determines the necessary size of the allocation in bytes.

for example if I write a new int that is going to have to request four bytes of memory allocate 4 bytes of memory once it has that number it goes and it asks the operating system what the I should say C standard library I need 4 bytes of memory please give it to me and that's where the fun begins now we

need to find a contiguous block of 4 bytes of memory now of course 4 bytes of memory is very very easy to find so there'll be Radek quick allocation but it still needs to find an address in memory where you have full bytes in a row once it does that it returns a pointer to that memory address so that you can begin using your data and storing data there and read me in access of reading and writing and doing all that fun stuff

there's something called a free list which actually maintains addresses that have bytes free not



# new 
first of all you'll see that it's an operator new is just an operator just like plus or minus or equals it's an operator which means that you can actually overload the operator and changes behavior


#  must use delete
when you do use the new keyword you have to remember that you must use delete so once we allocate all these variables like B and E we have to use the delete keyword which is also an operator

>note: delete also call the destructor 

* delete e;
delete is the regular fuction that calls the c function 
* free(e);
