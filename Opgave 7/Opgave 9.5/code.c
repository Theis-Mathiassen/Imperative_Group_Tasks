#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX 100

int DoubleCompare (const void *ip1, const void *ip2);

int main (void) {
    
    srand(time(NULL));

    double *pointer = (double*)malloc(sizeof(double) * MAX);
    if (pointer == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < MAX; i++) {
        pointer[i] = rand(); }

    for (int i = 0; i < MAX; i++) {
        printf("%lf\n", pointer[i]); }

    qsort(pointer, MAX, sizeof(double), DoubleCompare);


    for (int i = 0; i < MAX; i++) {
        printf("%lf\n", pointer[i]); }
    
    free(pointer);
    return EXIT_SUCCESS;
}

int DoubleCompare (const void *ip1, const void *ip2){
    int result;
    double *ipi1 = (double *)ip1;
    double *ipi2 = (double *)ip2;
    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;
    return result;
}