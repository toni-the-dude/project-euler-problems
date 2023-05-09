#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Work out the first ten digits of the sum of the one-hundred 50-digit numbers found in "13.in".
int main()
{
    FILE *fp = fopen("13.in", "r");
    unsigned char current_number[100];
    unsigned char total[200]; // use the later half only
    unsigned short carry = 0;

    // printf("hi");
    // initialize total
    for (unsigned short i = 0; i < 199; i++)
    {
        total[i] = '0';
    }
    unsigned short length_of_total = strlen(total) - 1;
    printf("\n%s\n", total);

    for (unsigned short i = 0; i < 100; i++)
    {
        fscanf(fp, "%s", &current_number);
        printf("%s\n", current_number);
            // printf("\n%c\n\n", current_number[49]);
        // for (unsigned short j = 49; j >= 0; j--) // SOMETHING TRULY EVIL
            // printf("%c", current_number[j]);
        // printf("\n");
        // fflush(stdin);
    }

    fclose(fp);

    return 0;
}