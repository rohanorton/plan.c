#include <stdio.h>

int main(int argc, char *argv[]) 
{
    // go through each string in argv
    int i = 0;

    while(i < argc) {
        printf("arg %d: %s\n",
                i, argv[i]);
        i++;
    }

    // lets make an array of strings:
    char *books[] = {
        "The Savage Anomoly",
        "Imagined Communities",
        "The Threat of Democracy",
        "The Making of Indebted Man"
    };

    int number_of_books = 4;
    
    i = 0; // remember to reinitialise the index! :P
    while(i < number_of_books) {
        printf("book %d: %s\n",
                i, books[i]);
        i++;
    }

    i = number_of_books;

    while(i > 0) {
        i--;
        printf("book %d: %s\n",
                i, books[i]);
    }

    return 0;
}
