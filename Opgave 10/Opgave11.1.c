#include <stdlib.h>
#include <stdio.h>
#include <math.h>



long _fib(long n, long *memory){     /* working program: fib-memo.c - an exercise*/
  long result = 0;

  /* for (int i = 0; i < n; i++) {
    printf("%li", memory[i]);
  } */

  if (n == 0) {
    result = 0;
  }
  else if (n == 1) {
      result = 1;
  }
  else if (memory[n-1] != 0) {
    /* printf("Hello from: %li\n", memory[n-1]); */
    result = memory[n-1];
  }
  else {
    result = _fib(n-1, memory) + _fib(n-2, memory);
    memory[n-1] = result;
  }

  return result;
}

long fib (long n) {
    long *memory = malloc(sizeof(long) * n);
    for (int i = 0; i < n; i++) {
        memory[i] = 0;
    }
    long result = _fib(n, memory);
    free(memory);
    return result;
}

int main(void) {
  long i;

  for(i = 0; i < 100; i++)
    printf("Fib(%li) = %li\n", i, fib(i));
  
  return 0;
}