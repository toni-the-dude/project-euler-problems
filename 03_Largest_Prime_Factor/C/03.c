#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(unsigned long long maybe_prime) {
    for(unsigned long long index = 2; index < maybe_prime / 2; index++) {
        if(maybe_prime % index == 0) return false;
    }
    return true;
}

int main() {
    unsigned long long *number = malloc(sizeof(unsigned long long));
    unsigned long long *prime_factor = malloc(sizeof(unsigned long long));
    unsigned long long *prime_factor_largest = malloc(sizeof(unsigned long long));

    *number = 600851475143;
    *prime_factor = 3;
    *prime_factor_largest = 2;

    while(*prime_factor < (unsigned long long)pow(2, 0.5 * log2(*number))) {
        if(*number % *prime_factor == 0 && is_prime(*prime_factor) == true) 
            *prime_factor_largest = *prime_factor;
        *prime_factor += 2;
    }

    printf("%llu\n", *prime_factor_largest);

    free(number);
    free(prime_factor);
    free(prime_factor_largest);
    return 0;
}