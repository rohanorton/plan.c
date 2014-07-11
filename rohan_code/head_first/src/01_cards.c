#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char card_name[3];
    int count = 0;
    puts("CARD COUNTER");
    puts("enter 'X' to end");
    puts("");
    while (card_name[0] != 'X') {
        puts("Enter card name: ");
        scanf("%2s", card_name);
        int val = 0;
        switch (card_name[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            case 'A':
                val = 11;
                break;
            case 'X':
                continue;
            default:
                val = atoi(card_name);
                if (1 > val || val > 10) {
                    printf("%d is not a valid card number\n", val);
                    continue;
                }
        }
        printf("The value of the card is %i\n", val);

        if (val >= 3 && val <= 6) {
            count++;
        } else if (val == 10) {
            // (10, K, Q, J)
            count--;
        }
        printf("Current count: %i\n", count);
    }
    return 0;
}
