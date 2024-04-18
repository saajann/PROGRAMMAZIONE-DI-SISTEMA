#include <stdio.h>

#define SIZE 128

void my_strcpy(char *dst, const char *src) {
    unsigned i = 0;
    for (; src[i]; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
}

int main () {
    char s[SIZE] = "ciao come va";
    char d[SIZE] = "";

    my_strcpy(d,s);

    printf("s: %s\n", s);
    printf("d: %s\n", d);

    return 0;
}