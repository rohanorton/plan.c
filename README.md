plan.c
======

Plan of action:
--------------

### Reading:
* Learn C the hard way (http://c.learncodethehardway.org/book/)
  * Ex1 Extra:
    * What is `int argc` and `char *argv[]` and how are they used? (read links)
      * http://stackoverflow.com/a/21733010
      * http://stackoverflow.com/a/3898070
      * http://stackoverflow.com/a/3024202
      * http://en.wikipedia.org/wiki/Main_function_%28programming%29#C_and_C.2B.2B
    * GCC goes through 4 steps (preprocessing, compilation, assembly and linking).
      Inspect the output after each of these steps (see *Overall Options* in the 
      man page for how to do this)
    * Compare final output (assembly?) of clang and gcc.
    * Find out why gcc gives exit code 13 and clang exit code 0 when return is omitted from main.
  * Ex2 Extra:
    * http://linux.die.net/man/1/gcc (just read about -g and -Wall)
    * http://www.gnu.org/software/make/
    * http://en.wikipedia.org/wiki/Make\_%28software%29
    * http://en.wikipedia.org/wiki/Autoconf
    * http://en.wikipedia.org/wiki/CMake
    * http://prateekvjoshi.com/2014/02/01/cmake-vs-make/
    * (Read Makes make file) http://git.savannah.gnu.org/cgit/make.git/tree/Makefile.am
    * (Read linux make file) https://github.com/torvalds/linux/blob/master/Makefile
    * What is `$<` in make and how does it work? (In regards to suffix and pattern rules).
    * What is `$@` in make and how does it work?
    * Does clang have -g and -Wall?? If not then what are the equivalent parameters?
  * Ex4 Extra:
    * valgrind docs: http://valgrind.org/docs/manual/ 
    * Pretty basic valgrind tutorial: http://pages.cs.wisc.edu/~bart/537/valgrind.html 
  * Ex7 Extra:
    * What’s a signed int? https://mail.python.org/pipermail/tutor/2004-January/027693.html
    * Why is there a signed char? http://stackoverflow.com/questions/451375/what-does-it-mean-for-a-char-to-be-signed 
    * http://stackoverflow.com/questions/2455806/unsigned-long-with-negative-value
    * Integer overflow http://phrack.org/issues/60/10.html#article
    * http://stackoverflow.com/questions/18195715/why-is-unsigned-integer-overflow-defined-behavior-but-signed-integer-overflow-is
    * http://www.airs.com/blog/archives/120 (signed overflow)
  * Ex10 Extra:
    * http://www.eskimo.com/~scs/cclass/int/sx4db.html (for loop comma)
    * http://stackoverflow.com/questions/1296843/what-is-the-difference-between-null-0-and-0 - Null
  * Ex11 Exta
    * http://www.cprogramming.com/tutorial/c/lesson15.html
    * http://www.cprogramming.com/tutorial/c/lesson9.html
    * http://www.reddit.com/r/C_Programming/comments/29yrrw/strcpy_implementation/
  * Ex15: Extra
    * I found this to be a bit clearer that the text regarding the differences between pointers and arrays… http://www.le.ac.uk/users/rjm1/cotter/page_59.htm 
    * also this… http://www.geeksforgeeks.org/difference-pointer-array-c/ 
    * Kind of obvious, but helpful to remember: “The `*` and `&` operators are opposites. The & operator takes a piece of data and tells you where it’s stored. The * operator takes an address and tells you what’s stored there”
    * Pointer arithmetic:
```c
array[2] == *(array + 2) == *(2 + array) == 2[array]
```
    * this is why it is important for pointers to have types: adding 1 to a char pointer will just add one (sizeof(char)) to the hexadecimal value… whereas, adding one to an int point will add 4 or 8 (sizeof(int)) to your hex address - this is apparently all worked out by the compiler.
  * Ex16 Extra
    * http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap
    * “When should you use the heap, and when should you use the stack? If you need to allocate a large block of memory (e.g. a large array, or a big struct), and you need to keep that variable around a long time (like a global), then you should allocate it on the heap. If you are dealing with relatively small variables that only need to persist as long as the function using them is alive, then you should use the stack, it's easier and faster. If you need variables like arrays and structs that can change size dynamically (e.g. arrays that can grow or shrink as needed) then you will likely need to allocate them on the heap, and use dynamic memory allocation functions like malloc(), calloc(), realloc() and free() to manage that memory "by hand". We will talk about dynamically allocated data structures after we talk about pointers.”: http://www.gribblelab.org/CBootcamp/7_Memory_Stack_vs_Heap.html
  * Ex17 Extra:
    * “safe” version of strncpy: http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/
    * strlcpy: http://stackoverflow.com/a/2115015/2800005
    * Struct packing: http://www.catb.org/esr/structure-packing/ 
    * https://www.youtube.com/watch?v=SXAr35BiqK8 - twos compliment (how most modern processors store integers)
   
  * Undefined behaviour and time travel! http://blogs.msdn.com/b/oldnewthing/archive/2014/06/27/10537746.aspx 
  * http://en.wikipedia.org/wiki/End-of-file 
  * http://man7.org/linux/man-pages/man3/errno.3.html 
  * TDD in C: http://eradman.com/posts/tdd-in-c.html - looks at how to write tests in C without the use of testing frameworks etc.… looks pretty interesting
* The C Programming Language - K&R
		* (http://www.eskimo.com/~scs/cclass/krnotes/top.html - perhaps read these notes along side K&R if any topics do not seem clear)
* 21st Century C
* OO in C
* Expert C Programming: Deep C Secrets
* Implement CONMAN project
* vim plugin for neo-vim maybe?
 
* Next steps and Further reading
* http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/
* http://stackoverflow.com/a/2926165 (understand and get the exaple working also read link)
* https://www.youtube.com/watch?v=2Z0yIguC5eU&list=PL56B156F5D73BBD77 - short video course on operating 
* http://duartes.org/gustavo/blog/post/kernel-boot-process/
* http://en.wikipedia.org/wiki/Processor_register
* http://blogs.msdn.com/b/oldnewthing/archive/2014/06/27/10537746.aspx 
* http://en.wikipedia.org/wiki/Endianness
* Make (see Ex2 links and also read Make book)
* http://www.open-std.org/jtc1/sc22/WG14/www/docs/n1256.pdf (c 99 standard)
* QEMU - can be used to understand computer architectures and assembly language
* TAOCP + MIX assembly language
* DB - https://class.stanford.edu/courses/Engineering/db/2014_1/about
* C++ for C programmers: https://www.coursera.org/course/cplusplus4c



### Make
[Rohan’s annotated makefile for “Learn C The Hard Way”] (https://gist.github.com/rohanorton/2a888f2295bc3be24d79)

### Pointers
http://stackoverflow.com/questions/13366083/why-does-the-arrow-operator-in-c-exist/13366168#13366168 - Why . and -> for referencing.

### Integers
http://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c/14695202#14695202 - cannot have negative integer literals.
http://stackoverflow.com/questions/2331751/does-the-size-of-an-int-depend-on-the-compiler-and-or-processor - what affects how big an integer is? (size in memory)

### Debugging
Really basic tutorial for using gdb to debug programs:
http://www.thegeekstuff.com/2010/03/debug-c-program-using-gdb/ 

valgrind docs: http://valgrind.org/docs/manual/ 

### Arrays
Finding length of integer arrays doesn’t work so maybe do this - http://stackoverflow.com/questions/10220124/how-to-know-the-end-of-int-array or
http://stackoverflow.com/a/11204534
`3[array]` - (Why does this work)[http://stackoverflow.com/questions/5546075/different-way-of-accessing-array-elements-in-c]

### Errors
http://en.wikipedia.org/wiki/Interrupt
Segmentation Fault (SIGSEGV)
http://en.wikipedia.org/wiki/Memory_protection
http://en.wikipedia.org/wiki/Segmentation_%28memory%29
http://en.wikipedia.org/wiki/Global_Descriptor_Table
http://en.wikipedia.org/wiki/Local_Descriptor_Table
http://en.wikipedia.org/wiki/Segmentation_fault
https://github.com/torvalds/linux/blob/master/arch/x86/mm/fault.c

### Security
On the effectiveness of address space ran http://web.stanford.edu/~blp/papers/asrandom.pdf 

### Strings
allocating a string as a pointer:
```c
char *my_string = “Hello”;
```
creates a string literal in read only memory

allocating a string as an array:
```c
char my_string[] = “Hello”;
```
creates an array of chars on the stack (therefore not read only)

### Functions
Syntax for function declarations 
* http://stackoverflow.com/questions/1630631/alternate-c-syntax-for-function-declaration-use-cases



