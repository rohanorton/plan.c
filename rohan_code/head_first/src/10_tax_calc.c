#include <stdio.h>

float total = 0.0;
short count = 0;
short tax_percent = 6;

float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0; // adding .0 makes this a float calculation
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}

int main(int argc, const char *argv[])
{
    float val;
    printf("Price of Item: ");
    while(scanf("%f", &val) == 1) {
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of Item: ");
    }
    printf("\nFinal Total: %.2f\n", total);
    printf("Number of items: %hi\n", count);
    return 0;
}
