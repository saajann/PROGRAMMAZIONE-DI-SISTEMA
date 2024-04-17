#include <stdio.h>

#define SIZE 10

void find_max(int *rmax, const int *values, unsigned size) {
    unsigned max= values[0];
    
    for (unsigned i = 1; i < size; i++) {
        if (values[i] > max) max = values[i];
    }
    
    *rmax = max;
}

int main (void) {
    int maxval;
    int vals[SIZE] = {1,3,5,77,9,43,2,12,4,5};
    
    find_max(&maxval, vals, SIZE);

    printf("%d", maxval);

    return 0;
}