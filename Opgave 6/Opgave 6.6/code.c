#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EUROS 0.89
#define KRONER 6.66
#define RUBLER 66.43
#define YEN 119.9
#define ITERATIONS 1000

int WidthOfLargestNumber ();

void Converter (double dollar, double *euro, double *kroner, double *rubler, double *yen);

int main (void) {
    printf("| Dollar | Euro  | Kroner | Rubler  | Yen      |\n");
    printf("________________________________________________\n");
    double dollar, euro, kroner, rubler, yen;
    for (int i = 1; i < ITERATIONS; i++) {
        dollar = i;
        int numberWidth = WidthOfLargestNumber();
        Converter(dollar, &euro, &kroner, &rubler, &yen);
        
        printf("| %5.2lf | %5.2lf | %6.2lf | %7.2lf | %8.2lf |\n", dollar, euro, kroner, rubler, yen);
        printf("________________________________________________\n");
    }
    return EXIT_SUCCESS;
}

void Converter (double dollar, double *euro, double *kroner, double *rubler, double *yen) {
    *euro = dollar * EUROS;
    *kroner = dollar * KRONER;
    *rubler = dollar * RUBLER;
    *yen = dollar * YEN;
}

int WidthOfLargestNumber () {
    return log10(YEN * ITERATIONS);
}