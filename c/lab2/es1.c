#include <stdio.h>
#define SIZE 5

void reversei(int *dst, const int *src, unsigned size) {
    for (int i = 0; i < size; i++) {
        dst[i] = src[size - 1 - i];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main(void) {
    int s[SIZE] = {1,2,3,4,5};
    int d[SIZE] = {};

    reversei(d,s,SIZE);

    printArray(s,SIZE);
    printf("\n");
    printArray(d,SIZE);

    return 0;
}