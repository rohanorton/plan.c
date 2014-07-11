#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;

    // goes through each string in argv
    // skipping argv[0] as this is merely 
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n",
                i, argv[i]);
    }
    
    // lets make our own array of strings
    char *places[] = {
        "york", 
        "leeds", 
        "manchester", 
        "london"
    };
    int num_places = 4;

    for (i = 0; i < num_places; i++) {
        printf("place %d: %s\n",
                i, places[i]);
    }

    return 0;
}
