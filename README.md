plan.c
======

#### Notes on learning C, operating systems and assembly


### Reading:
* [Learn C the hard way](http://c.learncodethehardway.org/book/)
  * Ex1 Extra:
    * What is `int argc` and `char *argv[]` and how are they used? (read links)
      * http://stackoverflow.com/a/21733010
      * http://stackoverflow.com/a/3898070
      * http://stackoverflow.com/a/3024202
      * [main()](
http://en.wikipedia.org/wiki/Main_function_%28programming%29#C_and_C.2B.2B)
    * GCC goes through 4 steps (preprocessing, compilation, assembly and 
      linking). Inspect the output after each of these steps (see *Overall 
      Options* in the man page for how to do this)
    * Compare final output (assembly?) of clang and gcc.
    * Find out why gcc gives exit code 13 and clang exit code 0 when return is 
      omitted from main.
  * Ex2 Extra:
    * [man gcc (just read about -g and -Wall)](http://linux.die.net/man/1/gcc)
    * [Make](http://www.gnu.org/software/make/)
    * [Make (wiki)](http://en.wikipedia.org/wiki/Make_%28software%29)
    * [Autoconf](http://en.wikipedia.org/wiki/Autoconf)
    * [Cmake](http://en.wikipedia.org/wiki/CMake)
    * [Cmake vs Make](http://prateekvjoshi.com/2014/02/01/cmake-vs-make/)
    * [Makes make file](
      http://git.savannah.gnu.org/cgit/make.git/tree/Makefile.am)
    * [Linux make file](https://github.com/torvalds/linux/blob/master/Makefile)
    * What is `$<` in make and how does it work? (In regards to suffix and
      pattern rules).
    * What is `$@` in make and how does it work?
    * Does clang have -g and -Wall?? If not then what are the equivalent
      parameters?
  * Ex4 Extra:
    * [valgrind docs] (http://valgrind.org/docs/manual/)
    * Pretty basic [valgrind tutorial] (
      http://pages.cs.wisc.edu/~bart/537/valgrind.html) 
  * Ex7 Extra:
    * [What’s a signed int?](
      https://mail.python.org/pipermail/tutor/2004-January/027693.html)
    * [Why is there a signed char?](
        http://stackoverflow.com/questions/451375/) 
    * [unsigned long with negative value](
        http://stackoverflow.com/questions/2455806/)
    * [Integer overflow](http://phrack.org/issues/60/10.html#article)
    * [Why is unsigned integer overflow defined but signed overflow undefined?](
       http://stackoverflow.com/questions/18195715/)
    * [Signed overflow](http://www.airs.com/blog/archives/120)
  * Ex10 Extra:
    * [For loop comma](http://www.eskimo.com/~scs/cclass/int/sx4db.html)
    * [Null](
http://stackoverflow.com/questions/1296843/)
  * Ex11 Exta
    * http://www.cprogramming.com/tutorial/c/lesson15.html
    * http://www.cprogramming.com/tutorial/c/lesson9.html
    * [strcpy implementation (reddit)](
   http://www.reddit.com/r/C_Programming/comments/29yrrw/strcpy_implementation/)
  * Ex15: Extra
    * I found [this](http://www.le.ac.uk/users/rjm1/cotter/page_59.htm)
      to be a bit clearer that the text regarding the differences between 
      pointers and arrays...
    * also [this] (http://www.geeksforgeeks.org/difference-pointer-array-c/)
    * Kind of obvious, but helpful to remember: "The `*` and `&` operators are 
      opposites. The `&` operator takes a piece of data and tells you where it’s
      stored. The `*` operator takes an address and tells you what’s stored 
      there"
    * Pointer arithmetic: `array[2] == *(array + 2) == *(2 + array) == 2[array]`
    * This is why it is important for pointers to have types: adding 1 to a char
      pointer will just add one (`sizeof(char)`) to the hexadecimal value...
      whereas, adding one to an int point will add 4 or 8 (`sizeof(int)`) to
      your hex address - this is apparently all worked out by the compiler.
  * Ex16 Extra
    * [What and where are the stack and the heap?](
      http://stackoverflow.com/questions/79923/)
    * "When should you use the heap, and when should you use the stack? If you 
      need to allocate a large block of memory (e.g. a large array, or a big 
      struct), and you need to keep that variable around a long time (like a 
      global), then you should allocate it on the heap. If you are dealing with
      relatively small variables that only need to persist as long as the 
      function using them is alive, then you should use the stack, it's easier 
      and faster. If you need variables like arrays and structs that can change
      size dynamically (e.g. arrays that can grow or shrink as needed) then you
      will likely need to allocate them on the heap, and use dynamic memory 
      allocation functions like malloc(), calloc(), realloc() and free() to 
      manage that memory "by hand". We will talk about dynamically allocated 
      data structures after we talk about pointers.":
      http://www.gribblelab.org/CBootcamp/7_Memory_Stack_vs_Heap.html
  * Ex17 Extra:
    * ["safe" version of strncpy](
      http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/)
    * [strlcpy]( http://stackoverflow.com/a/2115015/2800005)
    * [Struct packing](http://www.catb.org/esr/structure-packing/)
    * [Twos compliment (how most modern processors store integers) - Video](
        https://www.youtube.com/watch?v=SXAr35BiqK8)
  * [Undefined behaviour and time travel!](
     http://blogs.msdn.com/b/oldnewthing/archive/2014/06/27/10537746.aspx)
  * [End of File](http://en.wikipedia.org/wiki/End-of-file)
  * [Errno](http://man7.org/linux/man-pages/man3/errno.3.html)
  * [TDD in C](http://eradman.com/posts/tdd-in-c.html) - looks at how to write 
    tests in C without the use of testing frameworks etc...
* The C Programming Language - K&R
    * [K&R notes] (http://www.eskimo.com/~scs/cclass/krnotes/top.html)
      (perhaps read these notes along side K&R if any topics do not seem clear)
* 21st Century C
* OO in C
* Expert C Programming: Deep C Secrets
* Implement CONMAN project
* vim plugin for neo-vim maybe?
 
### Next steps and Further reading
* [Anatomy of a Program in Memory](
   http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)
* [Understand and get the example working also read link](
   http://stackoverflow.com/a/2926165)
* [Video playlist on operating systems](
   http://www.youtube.com/playlist?list=PL56B156F5D73BBD77)
* [Kernel Boot Process](
   http://duartes.org/gustavo/blog/post/kernel-boot-process)
* [Processor Register](http://en.wikipedia.org/wiki/Processor_register)
* http://blogs.msdn.com/b/oldnewthing/archive/2014/06/27/10537746.aspx 
* [Endianness](http://en.wikipedia.org/wiki/Endianness)
* Make (see Ex2 links and also read Make book)
* [C99 Standard](http://www.open-std.org/jtc1/sc22/WG14/www/docs/n1256.pdf)
* QEMU - can be used to understand computer architectures and assembly language
* TAOCP + MIX assembly language
* [DB](https://class.stanford.edu/courses/Engineering/db/2014_1/about)
* [C++ for C programmers](https://www.coursera.org/course/cplusplus4c)


## C Language

### Memory
* [Memory layout of a C Program](
  http://www.geeksforgeeks.org/memory-layout-of-c-program/)

### Pointers
* [Why `.` and `->` for referencing?](
http://stackoverflow.com/questions/13366083/)

### Integers
* [Cannot have negative integer literals](
http://stackoverflow.com/questions/14695118/)
* [What affects how big an integer is? (size in memory)](
http://stackoverflow.com/questions/2331751/)

### Casting
* What happens if you try the following?

```c
int a = 7;
int b = 2;
float c = a / b;
printf("c = %f\n", c);
```
An `int` divided by an `int` will always produce `int` values. In this case 3.
So one needs to use a cast to convert the numbers on the fly, like this...

```c
float c = (float)a / (float)b;
```

### Arrays
* Finding length of integer arrays doesn’t work so maybe do [this](
http://stackoverflow.com/questions/10220124/how-to-know-the-end-of-int-array) or
[this] (http://stackoverflow.com/a/11204534)
* `3[array]` [Why does this work??](http://stackoverflow.com/questions/5546075/)

### Errors
* [Interrupt](http://en.wikipedia.org/wiki/Interrupt)
* Segmentation Fault (SIGSEGV)
  * [Memory Protection](http://en.wikipedia.org/wiki/Memory_protection)
  * [Segmentation Memory](
      http://en.wikipedia.org/wiki/Segmentation_%28memory%29)
  * [Global Descriptor Table](
      http://en.wikipedia.org/wiki/Global_Descriptor_Table)
  * [Local Descriptor Table](
      http://en.wikipedia.org/wiki/Local_Descriptor_Table)
  * [Seg Fault](http://en.wikipedia.org/wiki/Segmentation_fault)
  * https://github.com/torvalds/linux/blob/master/arch/x86/mm/fault.c

### Security
* [On the effectiveness of address space ran](
   http://web.stanford.edu/~blp/papers/asrandom.pdf)

### Strings
* allocating a string as a pointer:
```c
char *my_string = "Hello";
```
  creates a string literal in read only memory

* allocating a string as an array:
```c
char my_string[] = "Hello";
```
   creates an array of chars on the stack (therefore not read only)

### Functions
* [Syntax for function declarations](
    http://stackoverflow.com/a/1631781)
* [ANSI vs K&R function syntax](http://stackoverflow.com/a/3092074)
* Use function declarations to show the compiler what the function will look
  like before you define them. If compiler finds a call to a function that 
  hasn't been declared yet, it presumes that the function returns an `int`.
* Include function declarations in a header file.
* Parameters: In C, parameters are passed to functions by value. So when calling
  a function, the values passed to it are assigned to the parameters. So... pass
  pointers, not structs, if you want changes to persist!

```c
void my_func(struct *my_struct)
{
  ...
}
...
struct my_struct this_struct = {foo, bar};
my_func(&this_struct);
```

### Enums
* [enum type](http://en.wikipedia.org/wiki/Enumerated_type#C)

### Structs
* [How is memory laid out in structs?](http://stackoverflow.com/a/2749009/)
* copy the contents of a struct to another struct creates a new struct in
  memory... but remember that if a string is a pointer, it will point to the
  same block of memory for both structs!
* [Using typedef to alias structs](http://stackoverflow.com/a/1675446/2800005)

### Bitfields
* It is possible to specify the number of bits that an item in a struct takes up
  using bitfields. This can be useful for reducing the size of structs.

```c
typedef struct {
  unsigned int boolean_answer:1; // will only store one bit of info (0-1)
  unsigned int day_of_week:3;    // will store integers 0-7
  unsigned int month:4;          // will store integers 0-15
} my_struct;
```

* Bitfields are only really useful when used in a group of items such as a
  struct, as the compiler will often pad out instances of bitfields used in
  isolation.

### Unions
* A union is a value that may have a number of different possible types (i.e. it
  could be an `int`, `float`, `char`)
* A union is defined in similar manner to a struct. But instead of allocating
  memory to each field as occurs for a struct, a union only allocates enough
  memory to statisfy it's largest field. This is because only one piece of data
  will ever be stored.

### Command Line Options parsing
* [Getopt wikipedia](http://en.wikipedia.org/wiki/Getopt)
* [Example usage of getopt](
  http://linuxprograms.wordpress.com/2012/06/22/c-getopt-example/)

### Reserved Words:

The entire list of reserved words in C in alphabetical order.

```c
auto
break
case
char
const
continue
default
do
double
else
entry
enum
extern
float
for
goto
if
int
long
register
return
short
signed
sizeof
static
struct
switch
typedef
union
unsigned
void
volatile
while
```
## Tools & Debugging

### Make
* [Rohan’s annotated makefile for “Learn C The Hard Way”](
https://gist.github.com/rohanorton/2a888f2295bc3be24d79)

### GDB
* [Really basic tutorial](
http://www.thegeekstuff.com/2010/03/debug-c-program-using-gdb/)
for using gdb to debug programs

### Valgrind
* [Valgrind docs](http://valgrind.org/docs/manual/)

### Size
* [Size man](https://sourceware.org/binutils/docs/binutils/size.html)

