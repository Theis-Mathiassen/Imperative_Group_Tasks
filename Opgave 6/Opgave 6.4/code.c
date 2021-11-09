#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double multi_apply (double (*function)(double), int n, int s);
double PercentUp (double val);
double PercentDown (double val);
double half(double x);

int main (void) {
    printf("Result: %lf.\n", multi_apply(&PercentUp, 4, 8));
    return EXIT_SUCCESS;
}


double multi_apply (double (*function)(double), int n, int s) {
    int newS = s;
    for (int i = 0; i < n; i++) {
        newS = function(newS);
    }
    return newS;
}

double PercentUp (double val) {
    return val * 1.2;
}

double PercentDown (double val) {
    return val * 0.8;
}

double half(double x){
    return x/2;
}