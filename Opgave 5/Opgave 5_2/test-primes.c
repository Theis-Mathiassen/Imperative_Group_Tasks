#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "primes.h"

long* FindPrimesBetween (long start, long end);

int main (void) {
    int PrimesToFind = 0;

    printf("Input amount of primes wanted:");
    scanf(" %d", &PrimesToFind);

    long *pointer;

    pointer = FindPrimesBetween(0, PrimesToFind);
    
    printf("Prime %d: %d\n", 1, *(pointer+1));
    return EXIT_SUCCESS;
}

/* while (primesFound <= PrimesToFind) {
        if (is_prime(currentPrimeCandidate)) {
            if (primesFound % (PrimesToFind / 10) == 0) {
                //printf("Primes found: %d\n", primesFound);
                //printf("PrimesToFind / 100: %d\n", (PrimesToFind/100));
                //printf("a mod b: %d\n", primesFound % (PrimesToFind / 100));
                printf("%d%% done.\n", (primesFound*100) / PrimesToFind);
            }
            //printf("Prime %d: %d\n", primesFound, currentPrimeCandidate);
            primesFound++;
        }
        currentPrimeCandidate++;
    }
*/

long * FindPrimesBetween (long start, long end) {
    long primesTemp[end - start];
    long primesFound = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            primesTemp[primesFound] = i;
            primesFound++;
        }
    }
    long primes[primesFound];
    for (int i = 0; i < primesFound; i++) {
        primes[i] = primesTemp[i];
    }
    return primes;
}