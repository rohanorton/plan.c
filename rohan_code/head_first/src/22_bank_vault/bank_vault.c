#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main(int argc, const char *argv[])
{
    char s[] = "Speak friend and enter";

    encrypt(s);

    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));

    // running encrypt again will decrypt the message
    encrypt(s);
    printf("Decrypted back to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));

    return 0;
}
