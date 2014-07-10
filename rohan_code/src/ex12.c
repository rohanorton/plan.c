#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 1 ) {
        printf("you only have no arguments, you suck!\n");
    } else if (argc > 1 && argc < 4) {
        printf("here's your arguments:\n");
    
        for (i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("you have too many arguments, you suck!\n");
    }
    return 0;
}
