#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'H';
    char first_name[] = "Rohan";
    char second_name[] = "Orton";

    printf("you are %d miles away\n", distance);
    printf("you have %f levels of power\n", power);
    printf("you have %f awesome super powers\n", super_power);
    printf("i have an initial %c\n", initial);
    printf("i have a first name %s\n", first_name);
    printf("i have a second name %s\n", second_name);
    printf("my whole name is %s %c. %s\n", first_name, initial, second_name);
    
    return 0;
}
