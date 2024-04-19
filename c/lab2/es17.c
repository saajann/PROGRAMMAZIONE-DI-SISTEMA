#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void init(int *v, unsigned size) {
    srand(time(NULL));
    for (unsigned i = 0; i < size; i++) {
        v[i] = rand() % 101;
    }
}

void sort(int *v, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size-1-i; j++) {
            int primo = v[j];
            int secondo = v[j+1];
            if (primo > secondo) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

int search(int *v, unsigned size, int value) {
    int ind = -1;
    for (unsigned i = 0; i < size; i++) {
        if (v[i] == value) {
            ind = i;
            break;
        }
    }
    return ind;
}

void show(int *v, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

int main (void) {
    int nums[SIZE];

    init(nums, SIZE);
    show(nums, SIZE);
    printf("%d\n", search(nums, SIZE, 4));

    sort(nums,SIZE);
    show(nums, SIZE);
    printf("%d\n", search(nums, SIZE, 4));

    return 0;
}