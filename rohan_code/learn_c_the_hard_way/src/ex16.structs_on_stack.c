#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, const char *argv[])
{
    //make two people structures
    struct Person joe = {
        .name = "Joe Alex",
        .age = 32,
        .height = 64,
        .weight =140 
    };
    struct Person frank = { 
        .name = "Frank Black",
        .age = 20,
        .height = 72, 
        .weight = 180
    };

    // print them out, and where they are in memory
    Person_print(joe);
    Person_print(frank);

    // make everyone age 20 years and print them out again
    joe.age += 20;
    joe.height-= 2;
    joe.weight+= 40;
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    return 0;
}
