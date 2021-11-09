#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int divide (int dividend, int divisor);
int modulus (int dividend, int divisor);

int main (void) {
    
    printf("Dividend: %d\n", divide(22, 4));
    printf("Modulus: %d\n", modulus(22, 4));
    return EXIT_SUCCESS;
}

int divide (int dividend, int divisor) {
    if (dividend < divisor) {
        return 0;
    } else {
        return 1 + divide(dividend - divisor, divisor);
    }
}

int modulus (int dividend, int divisor) {
    if (dividend < divisor) {
        return dividend;
    } else {
        return modulus(dividend - divisor, divisor);
    }
}