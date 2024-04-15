#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 128

void capitalize(char *dst, const char *src) {
    unsigned long len = strlen(src);
    for (unsigned i = 0; i < len; i++) {
        if (src[i-1] == ' ') {
            dst[i] = toupper(src[i]);
        } else {
            dst[i] = src[i];
        }
    }
}

int main (void) {
    char s[SIZE] = "give a man a fish and you feed him for a day; teach a man to fish and you feed him for a lifetime.";
    char d[SIZE] = "";

    capitalize(d,s);

    printf("%s\n", s);
    printf("%s\n", d);

    return 0;
}