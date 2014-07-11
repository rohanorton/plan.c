#include <stdio.h>

int main(int argc, const char *argv[])
{   
    // this would segfault
    // as the pointer is to a stringliteral in
    // read-only memory

//  char *cards = "JQK";

    char cards[] = "JQK";
    // by creating an array we 
    // copy the string into memory

    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts (cards);
    return 0;
}
