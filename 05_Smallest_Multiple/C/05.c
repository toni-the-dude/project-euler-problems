#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  unsigned long *product = malloc(sizeof(unsigned long));
  *product = 1;
  unsigned short *frequency = calloc(20, sizeof(unsigned short));

  for(unsigned short i = 2; i <= 20; i++) {
    unsigned short aux = i, j = 2, fr = 0;
    while(aux != 1) {
      if(aux % j == 0) {
        aux /= j, fr++;
        if(frequency[j] < fr) frequency[j] = fr;
      }
      else j++, fr = 0;
    }
  }

  for(unsigned short i = 2; i <= 19; i++)
    if(frequency[i] != 0) {
      // printf("Product:%lu i:%hu Frequency:%hu sizeof(frequency[i]):%lu\n", *product, i, frequency[i], sizeof(frequency[i]));
      *product *= round(pow(i, frequency[i]));
    }
  printf("%lu\n", *product);
  free(product);
  free(frequency);
  return 0;
}
