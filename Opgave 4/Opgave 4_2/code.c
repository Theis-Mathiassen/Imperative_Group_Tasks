#include <stdio.h>
#include <stdlib.h>

int main (void) {
  long m = 0, n = 0, k = 0, sum = 0;
  printf("Enter 3 numbers the last being positive:");
  scanf(" %d %d %d", &m, &n, &k);
  k = k < 0 ? -k : k;

  for (int i = m; i <= n; i++) {
      sum += i % k == 0 ? i : 0;
  }
  printf("Sum is: %d", sum);
  return EXIT_SUCCESS;
}