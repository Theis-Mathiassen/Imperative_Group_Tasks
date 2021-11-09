#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DELTA 0.1


// Opgave: Find ud af om punkt er indenfor, udenfor eller på cirklen periferien.
int main (void) {
  
  double r = 0; x = 0, y = 0;
  
  
  printf("Indtast r, x og y:\n");
  scanf(" %lf %lf %lf", &r, &x, &y);
  double dist = sqrt((x*x)+(y*y));
  
  printf(fabs(dist - r) < DELTA ? "Paa cirklen.\n" : (dist > r ? "Udenfor cirklen.\n" : "Indenfor cirklen.\n"));
  
  /*
  if (fabs(dist - r) < DELTA) {
    printf("Paa cirklen.\n");
  } else if (dist > r) {
    printf("Udenfor cirklen.\n");
  } else {
    printf("Indenfor cirklen.\n");
  }
  */

  
}