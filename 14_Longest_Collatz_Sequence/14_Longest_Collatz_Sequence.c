/*
The following iterative sequence is defined for the set of positive integers:
        n → n/2 (n is even)
        n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include <stdio.h>
#define LIMIT 1000000


// TRY RECURSIVE WITH HALF-ASSED MEMOIZATION
// IM NOT DOING HASH TABLES

unsigned long long memo[LIMIT];

unsigned long dynamicCollatzSequences(unsigned long num) 
{   
    // printf("%lu\n", num);
    // if(num > LIMIT) { printf("ERROR"); return 0; }
    // Base case
    if(num == 1) return 1;
    // else if(num <= LIMIT)
    //     if(memo[num] != 0) return memo[num];
    // Recursion
    if(num % 2 == 0) return 1 + dynamicCollatzSequences(num / 2);
    else             return 1 + dynamicCollatzSequences(num * 3 + 1);
}

int main() 
{
    unsigned long max = 0, maxIndex;
    for(unsigned long i = LIMIT - 1; i >= LIMIT / 2; i--)
    {
        memo[i] = dynamicCollatzSequences(i);
        printf("%lu ", memo[i]);
        if(memo[i] > max) max = memo[i], maxIndex = i;
    }
    printf("\nMAX:%lu\n", maxIndex);
    return 0;
}