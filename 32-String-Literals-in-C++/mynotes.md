* String Literals are always store in Read Only Memory


# What does “segmentation” mean?

>Memory is divided into segments, such as:
stack
heap
code
read-only data (.rodata)

>A segmentation fault happens when your program:
writes to a read-only segment
reads/writes outside its allocated segment
dereferences an invalid pointer