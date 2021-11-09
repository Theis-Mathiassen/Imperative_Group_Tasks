#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "primes.h"

int CheckVal(int num);
int CheckRange (int start, int end);

int main (void) {

    int input1 = 0;
    int input2 = 0;
    printf("Enter the range to search within, must be 2 intergers:\n");
    scanf(" %d %d", &input1, &input2);
    int lower = fmin(input1, input2);
    int upper = fmax(input1, input2);

    //Returns true if all numbers is the sum of two primes.
    int result = CheckRange(lower, upper);

    if (result == 0) {
        printf("Contradiction discovered!");
    } else {
        printf("All even numbers in specified range is the sum of two primes.");
    }

    return EXIT_SUCCESS;
}

int CheckRange (int start, int end) {
    int result = 1;
    start = fmax(6, start);
    //Make start even
    start += start % 2 != 0 ? 1 : 0;
    for (int i = start; i <= end; i += 2) {
        if (CheckVal(i) == 0) {
            result = 0;
        }
        if (i % 1000 == 0) {
            printf("Completed %ld%%.\n", ((i - start) * 100)/(end-start));
        }
    }
    return result;
}

int CheckVal(int num) {
    int resultFound = 0;
    for (int i = 1; i < num; i += 2) {
        //printf("Hello from I: %d\n", i);
        if (is_prime(i)) {
            if (is_prime(num - i)) {
                resultFound = 1;
            }
            /*
            for (int j = 0; j < num; j++) {
                //printf("Hello from J: %d\n", j);
                if (is_prime(j)) {
                    if (num == i + j) {
                        resultFound = 1;
                        //printf("Number: %d is the sum of %d and %d.\n", num, i, j);
                    }
                }
            }
            */
        }
    }
    if (resultFound) {
        return 1;
    } else {
        return 0;
    }
    
}