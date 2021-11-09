#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double mySqrt(double);
double mySqrt_ (double val, int resolution, int constant);

int main (void) {
    //double input = 0;
    //printf("Get square root of entered floating point number:");
    //scanf(" %lf", &input);

    for (int i = 1; i <= 250; i++) {
        printf("Number %d: sqrt(%d) = %lf & my_sqrt(%d) = %lf.\n", i, i, sqrt(i), i, mySqrt(i));
    }

    return EXIT_SUCCESS;
}
double mySqrt (double val) {
    return mySqrt_(val, 8, val);
}

double mySqrt_ (double val, int resolution, int constant) {
    if (resolution == 0) {
        return val;
    } else {
        return mySqrt_(0.5 * (val + (constant/val)), resolution - 1, constant);
    }
}