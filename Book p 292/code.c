#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
  int maxVal = 5;
  int lineNum = maxVal * 2 + 1;
  for (int i = 0; i < lineNum; i++) {
    for (int j = 0; j <= i - (fmax(0, i - lineNum / 2) * 2); j++) {
      printf(" %d", j);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}