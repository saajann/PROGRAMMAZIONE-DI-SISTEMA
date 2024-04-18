#include <stdio.h>

unsigned my_strlen(const char *src) {
    unsigned i = 0;
    for (; src[i]; i++) {};
    return i;
}

int main (void) {
    char str[] = "ciao ciao";
    unsigned len = my_strlen(str);
    printf("%d", len);
}