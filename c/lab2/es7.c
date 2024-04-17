#include <stdio.h>
#include <stdlib.h>

#define SIZE1 5
#define SIZE2 6

int cmpfunc (const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

void merge(int *dst, const int *a1, unsigned s1, const int *a2, unsigned s2) {
    for (unsigned i = 0; i < s1; i++) {
        dst[i] = a1[i];
    }
    for (unsigned i = s1; i < s1+s2; i++) {
        dst[i] = a2[i-s1];
    }
    qsort(dst, s1+s2, sizeof(int), cmpfunc);
}

int main (void) {
    int arr1[SIZE1] = {1,4,6,8,9};
    int arr2[SIZE2] = {0,3,5,6,7,10};
    int d[SIZE1+SIZE2] = {};

    merge(d,arr1,SIZE1,arr2,SIZE2);

    for (int i = 0; i < SIZE1+SIZE2; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}