#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct fraction {
    unsigned int numerator;
    unsigned int denominator;
};
typedef struct fraction fraction;

unsigned int gcd(unsigned int large, unsigned int small);
fraction Forkort (fraction frac);
void PrintFraction (char name[], fraction frac);
fraction MultiplyFractionWithNumber (fraction frac, int num);
fraction MultiplyFractionWithNumber2 (fraction frac, int num);
fraction MultiplyFractionWithFraction (fraction frac1, fraction frac2);
fraction SumTwoFraction (fraction frac1, fraction frac2);


int main (void) {
    
    fraction frac1 = {4,10};
    fraction frac2 = {3,7};

    PrintFraction("frac1", frac1);
    PrintFraction("frac2", frac2);


    PrintFraction("Forkort frac1", Forkort(frac1));
    PrintFraction("Multiply frac1 by 3", MultiplyFractionWithNumber2(frac1, 3));
    PrintFraction("Multiply frac1 by frac2", MultiplyFractionWithFraction(frac1, frac2));
    PrintFraction("Sum of frac1 and frac2", SumTwoFraction(frac1, frac2));


    return EXIT_SUCCESS;
}

fraction Forkort (fraction frac) {
    int gcdValue = gcd(frac.numerator, frac.denominator);
    frac.numerator /= gcdValue;
    frac.denominator /= gcdValue;
    return frac;
}

void PrintFraction (char name[], fraction frac) {
    printf("Name: %s is %d/%d\n", name, frac.numerator, frac.denominator);
    return;
}

/* fraction MultiplyFractionWithNumber (fraction frac, int num) {
    fraction newFrac = {frac.numerator * num, frac.denominator * num};
    return newFrac;
} */

/* This works */
fraction MultiplyFractionWithNumber2 (fraction frac, int num) {
    return (fraction){frac.numerator * num, frac.denominator * num};
}

fraction MultiplyFractionWithFraction (fraction frac1, fraction frac2) {
    return Forkort((fraction){frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator});
}

fraction SumTwoFraction (fraction frac1, fraction frac2) {
    int denominator1 = frac1.denominator;
    int denominator2 = frac2.denominator;

    frac1.numerator *= denominator2;
    frac1.denominator *= denominator2;
    frac2.numerator *= denominator1;
    frac2.denominator *= denominator1;

    return Forkort((fraction){frac1.numerator + frac2.numerator, frac1.denominator});
}


unsigned int gcd(unsigned int large, unsigned int small){
    unsigned int remainder; 
    while (small > 0){
        remainder = large % small;
        large = small;
        small = remainder;
    }
    return large;
}

