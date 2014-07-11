// The * and & operators are opposites. The & operator takes a piece
// of data and tells you where it’s stored. The * operator takes an
// address and tells you what’s stored there

#include <stdio.h>

void go_southeast(int *lat, int *lon)
{
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main(int argc, const char *argv[])
{
    int latitude = 32;
    int longitude = -64;
    go_southeast(&latitude, &longitude);
    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
    return 0;
}
