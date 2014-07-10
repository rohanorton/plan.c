#include <stdio.h>

int main()
{
    int height = 72;
    int age = 10;

    printf("I am %i years old.\n", age);
    printf("I am %i inches tall.\n", height);
    printf("\n");


    int iNum = 82;
    float fNum = 12.1234567890;
    double dNum = 12.1234567890;
    char cChar = 'r';
    
    // Printing integer values:
    // (%i and %d are interchangable it seems....
    // using %i feels more obvious to me though...)
    printf("Integer: %i \n", iNum);
    printf("Print integer as character: %c \n", iNum);
    printf("Print integer as float: %f \n", iNum);
    printf("Print integer as double: %lf \n", iNum);
    // using # prints leading "0x" prefix of hex
    printf("Print integer as hex: %#x \n", iNum);
    // using # prints leading "0" prefix of octal
    printf("Print integer as octal: %#o \n", iNum);
    printf("\n");

    // Printing character values:
    printf("Character: %c \n", cChar);
    printf("Print character as integer: %i \n", cChar);
    printf("Print character as float: %f \n", cChar);
    printf("Print character as double: %lf \n", cChar);
    // using # prints leading "0x" prefix of hex
    printf("Print character as hex: %#x \n", cChar);
    // using # prints leading "0" prefix of octal
    printf("Print character as octal: %#o \n", cChar);
    printf("\n");

    // Printing float values:
    printf("Float: %f \n", fNum);
    printf("Print float as character: %c \n", fNum);
    printf("Print float as integer: %i \n", fNum);
    printf("Print float as double: %lf \n", fNum);
    // using # prints leading "0x" prefix of hex
    printf("Print float as hex: %#x \n", fNum);
    // using # prints leading "0" prefix of octal
    printf("Print float as octal: %#o \n", fNum);
    printf("\n");

    // Printing double values:
    printf("Double: %lf \n", dNum);
    printf("Print double as character: %c \n", dNum);
    printf("Print double as integer: %i \n", dNum);
    printf("Print double as float: %f \n", dNum);
    // using # prints leading "0x" prefix of hex
    printf("Print double as hex: %#x \n", dNum);
    // using # prints leading "0" prefix of octal
    printf("Print double as octal: %#o \n", dNum);
    printf("\n");

    return 0;
}
