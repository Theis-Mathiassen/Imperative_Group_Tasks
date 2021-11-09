#include <stdio.h>
#include <stdlib.h>

int main (void) {
  long pop = 9870, popGoal = 30000, year = 0;
  
  while (pop < popGoal) {
      year++;
      pop = pop + pop/10;
      printf("Population is: %d and the year is: %d\n", pop, year);
  }
  
  return EXIT_SUCCESS;
}