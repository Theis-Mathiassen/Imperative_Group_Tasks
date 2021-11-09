#include <stdio.h>

int main (void) {
  long n = 0, sum = 0;
  printf("Enter a non negative number:");
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
      sum += i;
  }
  printf("Sum is: %d, and (n * (n + 1)) / 2 equals: %d", sum, (n * (n + 1)) / 2);
}

