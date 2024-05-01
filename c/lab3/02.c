// trovare valori diagonale principale e secondaria
#include <stdio.h>

#define SIZE 4

void diagonals(int *rdp, int *rds, unsigned cols, const int m[][cols]) {
    for (int i = 0; i < SIZE; i++) {
        rdp[i] = m[i][i];
        rds[i] = m[i][cols-1-i];
    }
}

int main (void) {
    int mat[SIZE][SIZE] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    int dp[SIZE] = {};
    int ds[SIZE] = {};

    diagonals(dp,ds,SIZE,mat);

    for (int i = 0; i < SIZE; i++) {
        printf("%2d %2d\n", dp[i], ds[i]);
    }

    return 0;
}