#include <stdio.h>
#include <string.h>
#define SIZE 128

void reverses(char *dst, const char *src) {
    unsigned long len = strlen(src);
    for (unsigned i = 0; i < len; i++) {
        dst[i] = src[len - i - 1];
    }
}

int main(void) {
    char s[SIZE] = "ciao come va";
    char d[SIZE] = "";

    reverses(d,s);

    printf("%s\n", s);
    printf("%s\n", d);
    
    return 0;
}