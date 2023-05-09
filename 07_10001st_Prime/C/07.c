#include <stdio.h>
#include <stdbool.h>

#define LIMIT 10001

bool is_prime(unsigned long long maybe_prime) {
    for(unsigned long long index = 2; index < maybe_prime / 2; index++) {
        if(maybe_prime % index == 0) return false;
    }
    return true;
}

int main() {
    unsigned int count = 1;
    unsigned long prime = 2;

    while(count <= LIMIT) {
        prime++;
        if(is_prime(prime) == true) count++;
    }

    printf("%lu\n", prime);

    return 0;
}