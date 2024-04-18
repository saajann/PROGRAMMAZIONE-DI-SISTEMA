#include <stdio.h>

#define SIZE 128

void my_strcat(char *dst, const char *src) {
    unsigned i = 0;
    for (; dst[i]; i++) {}

    unsigned j = 0;
    for (; src[j]; j++) {}

    for (unsigned k = 0; k < j; k++) {
        dst[i+k] = src[k];
    }
    
}

int main () {
    char s[SIZE] = "bene tu";
    char d[SIZE*2] = "ciao come va?";

    my_strcat(d,s);

    printf("s: %s\n", s);
    printf("d: %s\n", d);

    return 0;
}