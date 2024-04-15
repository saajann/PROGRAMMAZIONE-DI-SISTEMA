#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128

void rotate(char *dst, const char *src, char shift) {
    unsigned long len = strlen(src);
    for (unsigned i = 0; i < len; i++) {
        if (islower(src[i])) {
            char tmp = src[i] + shift;
            if (tmp > 'z') {
                tmp -= ('z'-'a'+1);
            }
            dst[i] = tmp;
        } else if (isupper(src[i])) {
            char tmp = src[i] + shift;
            if (tmp > 'Z') {
                tmp -= ('Z'-'A'+1);
            }
            dst[i] = tmp;
        } else {
            dst[i] = src[i];
        }
    }
}

int main(void) {
    char s[SIZE] = "ciao come va";
    char d[SIZE] = "";

    rotate(d,s,2);

    printf("%s\n", s);
    printf("%s", d);

    return 0;
}