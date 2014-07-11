#include <stdio.h>
void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    // this is 8 because arrays are treated as pointers
    printf("Message occupies %li bytes\n", sizeof(msg));
    // to prove the point...
    printf("Message is stored at %p\n", msg);
}

int main(int argc, const char *argv[])
{
    char quote[] = "Cookies make you fat";
    fortune_cookie(quote);
    return 0;
}
