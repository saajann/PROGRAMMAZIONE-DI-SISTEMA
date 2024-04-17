#include <stdio.h>

#define SIZE 10

void fibonacci(unsigned *dst, unsigned n) {
    dst[0] = 0;
    dst[1] = 1;
    for (unsigned i = 2; i < n; i++) {
        dst[i] = dst[i-1] + dst[i-2];
    }
}

int main (void) {
    unsigned fib[SIZE] = {};

    fibonacci(fib, SIZE);

    for (unsigned i = 0; i < SIZE; i++) {
        printf("%d ", fib[i]);
    }
    
    return 0;
}