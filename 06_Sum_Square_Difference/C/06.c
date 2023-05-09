#include <stdio.h>

unsigned long sum_of_squares(unsigned short limit) {
  unsigned long sum = 0;
  for(unsigned short i = 1; i <= limit; i++) {
    sum += i * i;
  }
  return sum;
}

unsigned long square_of_sum(unsigned short limit) {
  unsigned long sum = 0;
  for(unsigned short i = 1; i <= limit; i++) {
    sum += i;
  }
  sum *= sum;
  return sum;
}

int main() {
  unsigned short limit = 100;
  printf("%lu\n", square_of_sum(limit) - sum_of_squares(limit));
  return 0;
}
