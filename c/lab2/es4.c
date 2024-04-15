#include <stdio.h>
#define SIZE 10

long findi(int value, const int *values, unsigned size) {
    long ind = -1;
    for (unsigned i = 0; i < size; i++) {
        if (values[i] == value) {
            ind = i;
        }
    }
    return ind;
}

int main (void) {
    int vals[SIZE] = {0,1,2,3,4,5,6,7,8,9};

    long ind = findi(5, vals, SIZE);

    printf("%ld", ind);

    return 0;
}