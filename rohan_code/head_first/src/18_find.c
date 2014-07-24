#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theatre",
    "Luis: SLM ND likes books, theatre, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theatre",
    "Jed: DBM likes theatre, books and dining"
};

int sports_not_bieber(char *s)
{
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s, "sports") || strstr(s, "workout");
}

int ns_theatre(char *s)
{
    return strstr(s, "NS") && strstr(s, "theatre");
}

int arts_theatre_or_dining(char *s)
{
    return strstr(s, "arts") || strstr(s, "theatre") || strstr(s, "dining");
}

void find(int (*match)(char*))
{
    int i;
    puts("Search Results:");
    puts("--------------");
    for (i = 0; i < NUM_ADS; i++) {
        if(match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------");
}

int main(int argc, const char *argv[])
{
    find(sports_not_bieber);
    find(sports_or_workout);
    find(ns_theatre);
    find(arts_theatre_or_dining);
    return 0;
}
