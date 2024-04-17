#include <stdio.h>

#define SIZE 10

void find_minmax(int *rmin, int *rmax, const int *values, unsigned size) {
    int min = values[0];
    int max = values[0];
    
    for (unsigned i = 0; i < size; i++) {
        if (values[i] < min) min = values[i];
        if (values[i] > max) max = values[i];
    }
    
    *rmin = min;
    *rmax = max;
}

int main (void) {
    int maxval;
    int minval;
    int vals[SIZE] = {1,3,5,77,-9,43,2,12,4,5};

    find_minmax(&minval, &maxval, vals, SIZE);

    printf("min: %d\n", minval);
    printf("max: %d\n", maxval);

    return 0;
}