#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);
    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'R';
    name[1] = 'H';
    name[2] = 'O';
    name[3] = '\0';
   
    // then print out initialised 
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);
    printf("name: %s\n", name);

    char *another = "RHO";
    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);
    printf("another: %s\n", another);

    return 0; 
}
