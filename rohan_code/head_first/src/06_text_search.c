#include <stdio.h>
#include <string.h>

char tracks[][80] = {
   "I left my heart in Harvard Med School",
   "Newark, Newark - what a wonderful town",
   "Dancing with a Dork",
   "From here to maternity",
   "The girl from Iwo Jima"
};

void find_track(char search_for[]) 
{
    int i;
    for (i = 0; i < 5; i++) {
        if(strstr(tracks[i], search_for)) {
            printf("Track %i: %s\n", i, tracks[i]);
        }
    }
}

int main()
{
    char search_for[80];
    printf("Search; for: ");
    // for some weird reason couldn't get fgets to work
    fgets(search_for, 80, stdin);

    // fgets adds newline chars when hitting return...
    // this was causing a bug where string comparisons were
    // always returning false. So, check for newline char and 
    // set it to null
    if (search_for[strlen(search_for) - 1] == '\n') {
        search_for[strlen(search_for) - 1] = '\0';
    }

    find_track(search_for);
    return 0;
}
