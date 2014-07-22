#include <stdio.h>

typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;

// void happy_birthday(turtle t)
// will not work because parameters take values
// it is equivalent to saying turtle t = myrtle;
// i.e. it copies struct
void happy_birthday(turtle *t)
{
    (*t).age = (*t).age + 1;
    printf("Happy Birthday %s! You are now %i years old!\n",
            (*t).name, (*t).age);
}

int main(int argc, const char *argv[])
{
    turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    happy_birthday(&myrtle);
    printf("%s's age is now %i\n",
            myrtle.name, myrtle.age);
    return 0;
}
