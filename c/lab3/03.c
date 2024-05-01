#include <stdio.h>

void tabula_recta(char t[][26]) {
    char fila = 'a';
    char rec = 'a';
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            t[i][j] = rec;
            if (rec < 'z') {
                rec++;
            } else {
                rec = 'a';
            }
        }
        fila++;
        rec = fila;
    }
}

int main(void) {
    char tab[26][26] = { };

    tabula_recta(tab);

    for (long i = 0; i < 26; i++) {
        for(long j = 0; j < 26; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}