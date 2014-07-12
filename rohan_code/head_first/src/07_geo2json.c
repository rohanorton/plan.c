#include <stdio.h>

int main(int argc, const char *argv[])
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("{\n\"data\": [");
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if(started) {
            printf(",\n");
        } else {
            started = 1;
        }
        printf("{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\" }", latitude, longitude, info);
    }
    puts("\n]\n}");

    return 0;
}
