#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coefficient)
{
    printf("Weight: %3.2f lbs\n", weight);
    printf("Distance: %3.2f mile\n", distance);
    printf("Calories burned: %4.2f cal\n",
            coefficient * weight * distance);
}
