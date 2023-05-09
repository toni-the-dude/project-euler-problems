#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_pali(unsigned long maybe_pali) {
    unsigned long reverse = 0;
    unsigned long clone   = maybe_pali;

    while(clone > 0) {
        reverse = reverse * 10 + clone % 10;
        clone /= 10;
    }

    if(maybe_pali == reverse) return true;

    return false;
}

int main() {
    unsigned long *product = malloc(sizeof(unsigned long));
    bool run = true;
    
    *product = 1;

    for(unsigned long i = 999; i > 900; i--) {
        // if(i % 11 != 0) continue;
        for(unsigned long j = 999; j > 900; j--) {
            if(i * j > *product && is_pali(i * j) == true) 
                *product = i * j;
        }
    }

    printf("%lu\n", *product);

    free(product);
    return 0;
}