#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LASTNDIGITS pow(10, 10)
// Work out the last ten digits of the sum of the one-hundred 50-digit numbers found in "13.in".
int main() {
    FILE *fp = fopen("13.in", "r");
    unsigned char number[51];
    unsigned long long sum = 0;

    for(unsigned short i = 0; i < 100; i++) {
        unsigned long long temp = 0;
        unsigned short itr = 0;
        fscanf(fp, "%s", &number);

        for(unsigned short i = strlen(number) - 1; i > strlen(number) - 11; i--) {
            temp = round((number[i] - '0') * pow(10, itr) + temp);
            itr++;
        }

        sum = (unsigned long long)(sum + temp) % (unsigned long long)LASTNDIGITS;
    }

    printf("\n%llu\n", sum);
    fclose(fp);
    return 0;
}