#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void frequencies(unsigned *freqs, const char *src) {
    unsigned long len = strlen(src);
    for (unsigned i = 0; i < len; i++) {
        if (isalpha(src[i])) {
            freqs[tolower(src[i]) - 'a']++;
        }
    }
}

int main(void) {
    char alfa = 'a';
    int f[SIZE] = {};
    char s[] = "ciaoo";
    frequencies(f,s);
    for (int i = 0; i < SIZE; i++) {
        printf("%c --> %d\n", alfa ,f[i] );
        alfa++;
    }
}