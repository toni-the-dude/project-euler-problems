// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// Sieve of Eratosthenes is one of the oldest and easiest methods for finding prime numbers up to a given number.
#define LIMIT 2000000

unsigned long long sumPrimesEratos(unsigned long n) {
    bool A[n];
    unsigned long long sum = 0;

    for(unsigned long i = 0; i < n; i++) A[i] = true;

    for(unsigned long i = 2; i < sqrt(n); i++) {
        if(A[i] == true) {
            unsigned long j;
            j = i * i;
            while(j <= n) {
                A[j] = false;
                j += i;
            }
        }
    }

    for(unsigned long i = 2; i < n; i++) 
        if(A[i] == true) sum += i; 

    return sum;
}

int main() {

    printf("\nsum:%llu.\n", sumPrimesEratos(LIMIT));

    return 0;
}