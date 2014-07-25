#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again.");
}

void second_chance(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP");
}

void marriage(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Congratulations! your last date has contacted");
    puts("us with a proposal of marriage");
}

// create array of functions that maps to response enums
// enums are given index numbers starting from 0
// so... replies[DUMP] == dump()
void (*replies[])(response) = {dump, second_chance, marriage};

int main(int argc, const char *argv[])
{
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
        {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
    };
    
    int i;
    for (i = 0; i < 4; i++) {
        // use replies array to call related function
        // vvvvvvvvvvvvvvvv
        (replies[r[i].type])(r[i]);
        //                  ^^^^^^ 
        //                  and don't forget to pass the function
        //                  some params! :P
    }
    return 0;
}
