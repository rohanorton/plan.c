#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Billig", "Ellie",
        "Rosalie", "Graham", "Eleanor"
    };

    // safely set the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
                names[i], ages[i]);
    }
    printf("----\n");

    // set up the pointer for the start of the array
    int *cur_age = ages;
    char **cur_name = names;

    // the second way, using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
               *(cur_name + i), *(cur_age + i));
    }

    printf("----\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old, again.\n",
                cur_name[i], cur_age[i]);
    }

    printf("----\n");

    // forth way, using pointers in stupid complex way
    for (cur_age = ages, cur_name = names; 
            (cur_age - ages) < count; 
            cur_age++, cur_name++) 
    {
        printf("%s lived %d years so far\n",
                *cur_name, *cur_age);
    }

    return 0;
}
