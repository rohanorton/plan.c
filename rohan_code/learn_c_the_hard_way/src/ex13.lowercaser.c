#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("ERROR: You need at leastone argument.\n");
        return 1;
    }
    
    int i = 0;
    int j = 0;
    char letter;

    for (j = 1; j < argc; j++) {
        for (i = 0; letter = argv[j][i], letter != '\0'; i++) {
            switch(letter) {
                case 'A':
                    printf("a");
                    break;
                case 'B':
                    printf("b");
                    break;
                case 'C':
                    printf("c");
                    break;
                case 'D':
                    printf("d");
                    break;
                case 'E':
                    printf("e");
                    break;
                case 'F':
                    printf("f");
                    break;
                case 'G':
                    printf("g");
                    break;
                case 'H':
                    printf("h");
                    break;
                case 'I':
                    printf("i");
                    break;
                case 'J':
                    printf("j");
                    break;
                case 'K':
                    printf("k");
                    break;
                case 'L':
                    printf("l");
                    break;
                case 'M':
                    printf("m");
                    break;
                case 'N':
                    printf("n");
                    break;
                case 'O':
                    printf("o");
                    break;
                case 'P':
                    printf("p");
                    break;
                case 'Q':
                    printf("q");
                    break;
                case 'R':
                    printf("r");
                    break;
                case 'S':
                    printf("s");
                    break;
                case 'T':
                    printf("t");
                    break;
                case 'U':
                    printf("u");
                    break;
                case 'V':
                    printf("v");
                    break;
                case 'W':
                    printf("w");
                    break;
                case 'X':
                    printf("x");
                    break;
                case 'Y':
                    printf("y");
                    break;
                case 'Z':
                    printf("z");
                    break;
                default:
                    printf("%c", letter);
            }
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
