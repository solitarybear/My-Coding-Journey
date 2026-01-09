# Introduction
visibility is really a concept that belongs to object-oriented programming and really what it refers to is how visible certain members or methods of a class actually are and what I mean by visible is who can see them and who can call them and who can use them and all that stuff

visibility is something that has absolutely no effect on how your program actually runs and no effect on program performance or anything like that it is purely something that exists in the language for you to be able to write better code or to help you out with organizing in code that is it so there are three basic visibility modifiers that we have in C++ private protected and public in other languages such as Java or C sharp there are other keywords in Java for example you

can just not have a visibility modifier and that's kind of called the default visibility modifier in c-sharp there's something called internal in super boffo we just have three private protected public that's it 

* private means this only* this entity class can actually access these variables meaning it can read them and it can write them now I should say only asterisk because there is actually something called a friend in C++ it's like a whole keyword and everything called friend and what that actually enables you to do is label a class or a function as a friend of say this entity class and what a friend means is that a friend can actually access private members from classes

# protected 
protected is a little bit more visible than private less visible in public
# why visibility 
let's talk a little bit about why you might want to use visibility where you use visibility why you just make everything public yeah what's the deal with that 

so first of all making everything public is purely a bad idea for the purpose of actually you being a developer and writing code 
if it's just a matter of style it's just a matter of how can I write code that is easy to maintain easy to understand by people who are going to read this code and maybe extend the code 

it has nothing to do with performance nothing to do with this will generate different code absolutely not visibility is not something that CPU understands is not something your computer knows about 

it's just it's just something that humans have invented in order to help other humans and themselves
#
#
#
