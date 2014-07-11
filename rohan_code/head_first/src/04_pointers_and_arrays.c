#include <stdio.h>

void the_mating_game()
{
    int contestants[] = { 1, 2, 3 };
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf("I'm going to pick contestant number %i\n", 
            contestants[2]);
    // will print 2...
    // *choice is pointer to (beginning of) contestants array
    // contestants[0] (beginning of array) is set to 2.
}

void five_minute_mystery() 
{
    int doses[] = { 1, 3, 2, 1000 };
    printf("Issue dose %i\n", 3[doses]);
    // o_O  
}

void call_me()
{
    char *msg = "Don't call me";
    puts( msg + 6 );
}

int main(int argc, const char *argv[])
{
    the_mating_game();
    five_minute_mystery();
    call_me();
    return 0;
}
