#include <stdio.h>
#include "encrypt.h"

int main(int argc, const char *argv[])
{
    char msg[80];
    while (fgets(msg, 80, stdin)) {
        encrypt(msg);
        printf("%s", msg);
    }
    return 0;
}

