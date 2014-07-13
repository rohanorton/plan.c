#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, const char *argv[])
{
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %li bytes\n", sizeof(int));
    printf("\n");

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %f\n", FLT_MIN);
    printf("A float takes %li bytes\n", sizeof(float));
    printf("\n");

    printf("The value of DBL_MAX is %lf\n", DBL_MAX);
    printf("The value of DBL_MIN is %lf\n", DBL_MIN);
    printf("A double takes %li bytes\n", sizeof(double));
    printf("\n");

    printf("The value of CHAR_MAX is %i\n", CHAR_MAX);
    printf("The value of CHAR_MIN is %i\n", CHAR_MIN);
    printf("A char takes %li bytes\n", sizeof(char));
    printf("\n");

    return 0;
}
