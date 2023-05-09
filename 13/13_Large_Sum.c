#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LASTNDIGITS pow(10, 10)
// Work out the first ten digits of the sum of the one-hundred 50-digit numbers found in "13.in".
// note to self: use a long ass string
int main() {
    FILE *fp = fopen("13.in", "r");
    unsigned char      number[100];
    unsigned char      number2[100];
    unsigned short     carry = 0;

    fscanf(fp, "%s", &number);

    for(unsigned short i = 0; i < 99; i++) {
        fscanf(fp, "%s", &number2);
        carry = 0;
        unsigned short indexNum = strlen(number) - 1, indexNum2 = strlen(number2) - 1;
        while(indexNum >= 0 && indexNum2 >= 0) {
            unsigned short sum = round((number[i] - '0') + (number2[i] - '0'));
            carry += sum / 10;
            number[indexNum] = sum % 10;
            indexNum--;
            indexNum2--;

        }
        // carry += round(number[0] - '0');
        if(strlen(number) > 50)
            for(unsigned short i = 0; i < 99; i++) {

            }
    }   

    // printf("\n%llu\n", sum);
    fclose(fp);
    return 0;
}