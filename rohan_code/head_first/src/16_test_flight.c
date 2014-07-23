#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    // the strdup function copies a string to the heap:
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        // remember to free memory allocated with strdup!
        free(i->name);
        free(i);
    }
}

void display (island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next) {
        printf("Name: %s is open: %s-%s\n",
                i->name, i->opens, i->closes);
    }
}

int main(int argc, const char *argv[])
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for (; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL) {
            start = next;
        }
        if (i != NULL) {
            i->next = next;
        }
    }
    display(start);
    release(start);

    return 0;
}
