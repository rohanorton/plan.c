#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

int compare_names(const void* a, const void* b)
{
    // a string is a pointer to a char,
    // so the pointers you are giving are pointers to pointers
    char** name_a = (char**)a;
    char** name_b = (char**)b;
    // need to use the * operator to find the actual strings
    return strcmp(*name_a, *name_b);
}

int compare_name_lengths(const void* a, const void* b)
{
    char** name_a = (char**)a;
    char** name_b = (char**)b;
    return strlen(*name_a) - strlen(*name_b);
}

int main(int argc, const char *argv[])
{
    int scores[] = {543,323,32,554,11,3,112};
    int i;
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("These are the scores in descending order:");
    for (i = 0; i < 7; i++) {
        printf("Score = %i\n", scores[i]);
    }
    
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);
    puts("These are the names in order:");
    for (i = 0; i < 4; i++) {
        printf("Name = %s\n", names[i]);
    }

    // lets try create our own :)
    // I want to sort by name length...
    char *more_names[] = {"Ali", "Susannah", "Constantine", "Ellie", "E", "Brodrick", "Emmanuelle", "Rohan"};
    size_t more_names_length = sizeof(more_names) / sizeof(char*);

    qsort(more_names, more_names_length, sizeof(char*), compare_name_lengths);
    puts("These are the names in order:");
    for (i = 0; i < more_names_length; i++) {
        printf("Name = %s\n", more_names[i]);
    }

    return 0;
}
