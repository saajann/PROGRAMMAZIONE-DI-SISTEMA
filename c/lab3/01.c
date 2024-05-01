// somma elementi cornice della matrice
#include <stdio.h>

long matrix_edge(unsigned rows, unsigned cols, int m[][cols]) {
    long val = 0;
    // somma prima e ultima riga
    for (int i = 0; i < cols; i++) {
        val += m[0][i];
        val += m[rows-1][i];
    }
    // somma prima e ultima colonna, esclusi elementi della prima e ultima riga
    for (int i = 1; i < rows-1;i++) {
        val += m[i][0];
        val += m[i][cols-1];
    }
    
    return val;
}

int main (void) {
    int mat[4][4] = {
            {2,4,6,1},
            {1,4,7,3},
            {0,3,5,2},
            {4,7,9,2}
    };
    
    long val = matrix_edge(4,4,mat);
    
    printf("%d", val);
    
    return 0;
}