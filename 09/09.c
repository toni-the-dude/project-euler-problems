// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
#include <stdio.h>
#include <stdbool.h>

#define NUMBER 1000

// void find_pytha3() {
    // unsigned long a, b, c;
    // bool run = true;
    // unsigned long m = 2, n; unsigned long product;
    // while(m <= NUMBER / 100 && run == true) {
    //     for(n = 1; n < m; n++) {
    //         if(m % 2 == 1 && n % 2 == 1) continue;
    //         if(m % n == 0) continue;
    //         a = m * m - n * n;
    //         b = 2 * m * n;
    //         c = m * m + n * n;
    //         printf("%d %d %d\n", a, b, c);
    //         if((a + b + c) == NUMBER) {
    //             product = a * b * c;
    //             printf("%lu\n", product);
    //             run = false;
    //             break;
    //         }
    //     } 
    //     m++;
    // }
void find_pytha3()
{
    int a, b, c = 0;
    int m = 2;
    int product;
    while (c < NUMBER) {
        for (int n = 1; n < m; ++n) {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;
            if (c > NUMBER)
                break;
            printf("%d %d %d\n", a, b, c);
            if((a + b + c) == NUMBER) {
                product = a * b * c;
                printf("%lu\n", product);
                break;
            }
        }
        m++;
    }
}

int main() {
    find_pytha3();
    return 0;
}
/*
    a = m^2-n^2
    b = 2*m*n
    c = m^2+n^2

(i) m, n are any two positive integers
(ii) m > n
(iii) m and n are coprime and both should not be odd numbers (at once)
*/