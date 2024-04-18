#include <stdio.h>
#include <string.h>

int my_strcmp(const char *s1, const char *s2) {
    unsigned long len1 = strlen(s1);
    unsigned long len2 = strlen(s2);
    if (len1 == len2) {
        for (unsigned i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                return 1;
            }
        }
    }
    else {
        return 1;
    }
    return 0;
}

int main (void) {
    char s1[] = "ciao";
    char s2[] = "ciao";
    char s3[] = "bau";

    printf("s1 s2 %d\n", my_strcmp(s1,s2));
    printf("s1 s3 %d\n", my_strcmp(s1,s3));

}